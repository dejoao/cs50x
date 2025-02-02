-- Keep a log of any SQL queries you execute as you solve the mystery.

--repot cena do crime - ve relatos das testemenhas
SELECT * FROM crime_scene_reports
   WHERE day = 28 AND month = 7;

--testemunhas - checar ligacoes de menos de um minuto; descobri qual primeiro voo de amanha 29/07/2024; verificar passagens compradas proximo da hora do roubo.
SELECT * FROM interviews
   WHERE day = 28 AND month = 7;

--161|Ruth|2024|7|28|Em algum momento, dez minutos após o roubo, vi o ladrão entrar em um carro no 
--estacionamento da padaria e ir embora. Se você tiver imagens de segurança do estacionamento da padaria, 
--talvez queira procurar carros que saíram do estacionamento nesse período.

--162|Eugene|2024|7|28|Não sei o nome do ladrão, mas era alguém que eu reconheci. Mais cedo esta manhã,
--antes de chegar à padaria de Emma, ​​eu estava passando pelo caixa eletrônico na Leggett Street e vi 
--o ladrão sacando dinheiro.

--163|Raymond|2024|7|28|Quando o ladrão estava saindo da padaria, ele ligou para alguém que falou com ele 
--por menos de um minuto. Na ligação, ouvi o ladrão dizer que planejava pegar o primeiro voo de Fiftyville 
--amanhã. O ladrão então pediu à pessoa do outro lado da linha para comprar a passagem aérea.

-- ligacoes em 28/07 de menos de um minuto
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60;

--221|(130) 555-0289|(996) 555-8899|2024|7|28|51
--224|(499) 555-9472|(892) 555-8872|2024|7|28|36
--233|(367) 555-5533|(375) 555-8161|2024|7|28|45
--251|(499) 555-9472|(717) 555-1342|2024|7|28|50
--254|(286) 555-6063|(676) 555-6554|2024|7|28|43
--255|(770) 555-1861|(725) 555-3243|2024|7|28|49
--261|(031) 555-6622|(910) 555-3251|2024|7|28|38
--279|(826) 555-1652|(066) 555-9701|2024|7|28|55
--281|(338) 555-6650|(704) 555-2131|2024|7|28|54

-- voos do dia 29/07/2024 - verificar passageiros do voo 36|8|4|2024|7|29|8|20
SELECT * FROM flights 
   WHERE day = 29 AND month = 7 AND year = 2024;

-- passport passageiros 
SELECT passengers.passport_number
   FROM passengers
   JOIN flights ON flights.id = passengers.flight_id
   

--7214083635
--1695452385
--5773159633
--1540955065
--8294398571
--1988161715
--9878712108
--8496433585

-- pessoas que estavam no voo do dia 29 e fizeram ligacoes no dia 28
SELECT * FROM people
WHERE passport_number IN (7214083635, 1695452385, 5773159633, 1540955065, 
                          8294398571, 1988161715, 9878712108, 8496433585)
AND phone_number IN ('(130) 555-0289', '(499) 555-9472', '(367) 555-5533', 
                     '(286) 555-6063', '(770) 555-1861', '(031) 555-6622',
                     '(826) 555-1652', '(338) 555-6650');

--395717|Kenny|(826) 555-1652|9878712108|30G67EN
--398010|Sofia|(130) 555-0289|1695452385|G412CB7 
--449774|Taylor|(286) 555-6063|1988161715|1106N58 
--560886|Kelsey|(499) 555-9472|8294398571|0NTHK55 
--686048|Bruce|(367) 555-5533|5773159633|94KL13X

-- logs estacionamento da padaria 10 minutos depois do roubo 10:25am
SELECT * FROM bakery_security_logs
   WHERE day = 28 AND month = 7 AND hour = 10;

--264|2024|7|28|10|20|exit|G412CB7
--265|2024|7|28|10|21|exit|L93JTIZ
--266|2024|7|28|10|23|exit|322W7JE
--267|2024|7|28|10|23|exit|0NTHK55
--268|2024|7|28|10|35|exit|1106N58

-- pessoas que estavam no voo do dia 29 e fizeram ligacoes no 28 e sairam da padaria proximo do horario do roubo
--398010|Sofia|(130) 555-0289|1695452385|G412CB7 
--449774|Taylor|(286) 555-6063|1988161715|1106N58 
--560886|Kelsey|(499) 555-9472|8294398571|0NTHK55 

-- pessoas que estavam sacando dinheiro na Leggett Street de manha 
SELECT * FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2024 
AND atm_location LIKE 'Leggett Street';

--246|28500762|2024|7|28|Leggett Street|withdraw|48
--264|28296815|2024|7|28|Leggett Street|withdraw|20
--266|76054385|2024|7|28|Leggett Street|withdraw|60
--267|49610011|2024|7|28|Leggett Street|withdraw|50
--269|16153065|2024|7|28|Leggett Street|withdraw|80
--275|86363979|2024|7|28|Leggett Street|deposit|10
--288|25506511|2024|7|28|Leggett Street|withdraw|20
--313|81061156|2024|7|28|Leggett Street|withdraw|30
--336|26013199|2024|7|28|Leggett Street|withdraw|35

-- descobri de quem sao as contas
SELECT * FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE bank_accounts.account_number IN (28500762, 28296815, 76054385, 
                                       49610011, 16153065, 25506511, 
                                       81061156, 26013199);

--686048|Bruce|(367) 555-5533|5773159633|94KL13X|49610011|686048|2010
--514354|Diana|(770) 555-1861|3592750733|322W7JE|26013199|514354|2012
--458378|Brooke|(122) 555-4581|4408372428|QX4YZN3|16153065|458378|2012
--395717|Kenny|(826) 555-1652|9878712108|30G67EN|28296815|395717|2014
--396669|Iman|(829) 555-5269|7049073643|L93JTIZ|25506511|396669|2014
--467400|Luca|(389) 555-5198|8496433585|4328GD8|28500762|467400|2014
--449774|Taylor|(286) 555-6063|1988161715|1106N58|76054385|449774|2015 .
--438727|Benista|(338) 555-6650|9586786673|8X428L0|81061156|438727|2018

-- para qual cidade taylor foi
SELECT * FROM flights 
   WHERE day = 29 AND month = 07 AND year = 2024
   AND hour = 8;

--36|8|4|2024|7|29|8|20

SELECT * FROM airports 
   JOIN flights ON flights.destination_airport_id = airports.id
   WHERE flights.day = 29 AND flights.month = 07 AND flights.year = 2024
   AND flights.hour = 8;

--4|LGA|LaGuardia Airport|New York City|36|8|4|2024|7|29|8|20

-- descobri que é o cumplice - atraves do numero que recebeu a ligacao
SELECT * FROM phone_calls WHERE caller LIKE '(286) 555-6063'
   ...> AND day = 28 AND month = 7 AND duration < 60;

--254|(286) 555-6063|(676) 555-6554|2024|7|28|43

SELECT name FROM people
   WHERE phone_number LIKE '(676) 555-6554';

--James

SELECT * FROM people
   WHERE name LIKE 'James';

--250277|James|(676) 555-6554|2438825627|Q13SVG6

SELECT * FROM bank_accounts
   JOIN people ON people.id = bank_accounts.person_id
   WHERE people.name LIKE 'James';



-- RECOMECAR

-- reports no dia do crime
SELECT * FROM crime_scene_reports
   WHERE day = 28 AND month = 7 AND year = 2024
   AND street LIKE 'Humphrey Street';

-- 295|2024|7|28|Humphrey Street|O roubo do pato CS50 ocorreu às 10:15 da manhã na
-- padaria da Humphrey Street. As entrevistas foram conduzidas hoje com três testemunhas que
-- estavam presentes no momento – cada uma das transcrições de suas entrevistas menciona a padaria.

--entrevista testemunhas
 SELECT * FROM interviews
   WHERE day = 28 AND month = 7 AND year = 2024
   AND transcript LIKE '%bakery%';

-- 161|Ruth|2024|7|28|Em algum momento, dez minutos após o roubo, vi o ladrão entrar em um carro no 
-- estacionamento da padaria e ir embora. Se você tiver imagens de segurança do estacionamento da padaria, 
-- talvez queira procurar carros que saíram do estacionamento nesse período.

-- 162|Eugene|2024|7|28|Não sei o nome do ladrão, mas era alguém que eu reconheci. Mais cedo esta manhã, 
-- antes de chegar à padaria da Emma, ​​eu estava passando pelo caixa eletrônico na Leggett Street e vi o 
-- ladrão sacando dinheiro.

-- 163|Raymond|2024|7|28|Quando o ladrão estava saindo da padaria, ele ligou para alguém que falou com ele por menos 
-- de um minuto. Na ligação, ouvi o ladrão dizer que estava planejando pegar o primeiro voo de Fiftyville 
-- amanhã. O ladrão então pediu à pessoa do outro lado da linha para comprar a passagem aérea.

-- checkar logs de seguranca da padaria - roubo foi as 10:15AM
SELECT * FROM bakery_security_logs
   WHERE day = 28 AND month = 7 AND year = 2024
   AND hour = 10 AND activity LIKE 'exit';

-- license_plate de quem saiu da padaria na hora do roubo
-- 260|2024|7|28|10|16|exit|5P2BI95
-- 261|2024|7|28|10|18|exit|94KL13X
-- 262|2024|7|28|10|18|exit|6P58WS2
-- 263|2024|7|28|10|19|exit|4328GD8
-- 264|2024|7|28|10|20|exit|G412CB7
-- 265|2024|7|28|10|21|exit|L93JTIZ
-- 266|2024|7|28|10|23|exit|322W7JE
-- 267|2024|7|28|10|23|exit|0NTHK55
-- 268|2024|7|28|10|35|exit|1106N58

-- Placas com nomes
SELECT * FROM people
WHERE license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55', '1106N58');

-- 221103|Vanessa|(725) 555-4692|2963008352|5P2BI95
-- 243696|Barry|(301) 555-4174|7526138472|6P58WS2
-- 396669|Iman|(829) 555-5269|7049073643|L93JTIZ
-- 398010|Sofia|(130) 555-0289|1695452385|G412CB7
-- 449774|Taylor|(286) 555-6063|1988161715|1106N58
-- 467400|Luca|(389) 555-5198|8496433585|4328GD8
-- 514354|Diana|(770) 555-1861|3592750733|322W7JE
-- 560886|Kelsey|(499) 555-9472|8294398571|0NTHK55
-- 686048|Bruce|(367) 555-5533|5773159633|94KL13X


-- saques de dinheiro na Leggett Street
SELECT * FROM atm_transactions
   WHERE day = 28 AND month = 7 AND year = 2024
   AND atm_location LIKE 'Leggett Street'
   AND transaction_type LIKE 'withdraw';

-- account_number de quem sacou dinheiro no dia 28
-- 246|28500762|2024|7|28|Leggett Street|withdraw|48
-- 264|28296815|2024|7|28|Leggett Street|withdraw|20
-- 266|76054385|2024|7|28|Leggett Street|withdraw|60
-- 267|49610011|2024|7|28|Leggett Street|withdraw|50
-- 269|16153065|2024|7|28|Leggett Street|withdraw|80
-- 288|25506511|2024|7|28|Leggett Street|withdraw|20
-- 313|81061156|2024|7|28|Leggett Street|withdraw|30
-- 336|26013199|2024|7|28|Leggett Street|withdraw|35

--Donos do account_number
SELECT * FROM people
   JOIN bank_accounts ON bank_accounts.person_id = people.id
   WHERE bank_accounts.account_number IN ('28500762', '28296815', '76054385', '49610011', '16153065', '25506511', '81061156', '26013199');

-- 686048|Bruce|(367) 555-5533|5773159633|94KL13X|49610011|686048|2010 .
-- 514354|Diana|(770) 555-1861|3592750733|322W7JE|26013199|514354|2012 .
-- 458378|Brooke|(122) 555-4581|4408372428|QX4YZN3|16153065|458378|2012
-- 395717|Kenny|(826) 555-1652|9878712108|30G67EN|28296815|395717|2014
-- 396669|Iman|(829) 555-5269|7049073643|L93JTIZ|25506511|396669|2014 .
-- 467400|Luca|(389) 555-5198|8496433585|4328GD8|28500762|467400|2014 .
-- 449774|Taylor|(286) 555-6063|1988161715|1106N58|76054385|449774|2015 .
-- 438727|Benista|(338) 555-6650|9586786673|8X428L0|81061156|438727|2018

-- PESSOAS QUE SACARAM DINHEIRO NA Leggett Street E SAIRAM DO ESTACIONAMENTO NA HORA DO CRIME

-- 449774|Taylor|(286) 555-6063|1988161715|1106N58|76054385|449774|2015 
-- 467400|Luca|(389) 555-5198|8496433585|4328GD8|28500762|467400|2014 
-- 396669|Iman|(829) 555-5269|7049073643|L93JTIZ|25506511|396669|2014 
-- 514354|Diana|(770) 555-1861|3592750733|322W7JE|26013199|514354|2012
-- 686048|Bruce|(367) 555-5533|5773159633|94KL13X|49610011|686048|2010 

-- quais desses ligou para alguem por menos de um minuto
SELECT * FROM phone_calls
   WHERE day = 28 AND month = 7 AND year = 2024
   AND caller IN ('(286) 555-6063', '(389) 555-5198', '(829) 555-5269', '(770) 555-1861', '(367) 555-5533')
   AND duration <= 60; 

-- 233|(367) 555-5533|(375) 555-8161|2024|7|28|45 Bruce 686048|Bruce|(367) 555-5533|5773159633|94KL13X|49610011|686048|2010 
-- 254|(286) 555-6063|(676) 555-6554|2024|7|28|43 Taylor 449774|Taylor|(286) 555-6063|1988161715|1106N58|76054385|449774|2015 
-- 255|(770) 555-1861|(725) 555-3243|2024|7|28|49 Diana 514354|Diana|(770) 555-1861|3592750733|322W7JE|26013199|514354|2012

--quem desses estava no primeiro voo do dia 29 fiftyville

--primeiro voo
SELECT * FROM flights
   WHERE day = 29 AND month = 7 AND year = 2024;

36|8|4|2024|7|29|8|20

-- estavam no primeiro voo
SELECT * FROM passengers
   JOIN flights ON flights.id = passengers.flight_id
   WHERE day = 29 AND month = 7 AND year = 2024 AND hour = 8
   AND passport_number IN ('5773159633', '1988161715', '3592750733');

-- ESTAVAM NO VOO, LIGARAM PARA ALGUEM POR MENOS DE UM MINUTO, SACARAM DINHEIRO, SAIRAM DA PADARIA NA MESMA HORA
-- 36|5773159633|4A|36|8|4|2024|7|29|8|20 Bruce
-- 36|1988161715|6D|36|8|4|2024|7|29|8|20 Taylor

--quem é dono desse numero (375) 555-8161
SELECT * FROM people
   WHERE phone_number LIKE '(375) 555-8161';

-- 864400|Robin|(375) 555-8161||4V16VO0