SELECT name, (victories+defeats+draws) as matches, victories, defeats, draws, (3*victories+draws) as score 
FROM
  (SELECT
      teams.name, 
      (SELECT COUNT(*) from matches WHERE (matches.team_1=teams.id and matches.team_1_goals > matches.team_2_goals) 
          OR (matches.team_2 = teams.id AND matches.team_1_goals < matches.team_2_goals)) as victories,

      (SELECT COUNT(*) from matches WHERE (matches.team_1=teams.id and matches.team_1_goals < matches.team_2_goals) 
          OR (matches.team_2 = teams.id AND matches.team_1_goals > matches.team_2_goals)) as defeats,

      (SELECT COUNT(*) from matches WHERE (matches.team_1 = teams.id OR matches.team_2 = teams.id) 
          AND (matches.team_1_goals = matches.team_2_goals)) as draws
  from teams) as pont
ORDER BY score DESC