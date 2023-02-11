-- Prepare->SQL->Basic Join->hallenges

SELECT Challenges.hacker_id, Hackers.name, count(Challenges.challenge_id) AS count 
FROM Hackers JOIN Challenges ON Hackers.hacker_id = Challenges.hacker_id
GROUP BY Challenges.hacker_id, Hackers.name 
HAVING count = (SELECT count(challenge1.challenge_id) FROM Challenges AS challenge1 GROUP BY challenge1.hacker_id 
            ORDER BY count(*) desc limit 1) or
count NOT IN (SELECT count(challenge2.challenge_id) FROM Challenges AS challenge2 GROUP BY challenge2.hacker_id 
            HAVING challenge2.hacker_id <> Challenges.hacker_id)
ORDER BY count DESC, Challenges.hacker_id;

