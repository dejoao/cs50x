-- Keep a log of any SQL queries you execute as you solve the mystery.

--repot cena do crime - ve relatos das testemenhas
SELECT * FROM crime_scene_reports
   WHERE day = 28 AND month = 7;

--testemunhas - checar ligacoes de menos de um minuto; descobri qual primeiro voo de amanha 29/07/2024; verificar passagens compradas proximo da hora do roubo.
SELECT * FROM interviews
   WHERE day = 28 AND month = 7;

161|Ruth|2024|7|28|Em algum momento, dez minutos após o roubo, vi o ladrão entrar em um carro no 
estacionamento da padaria e ir embora. Se você tiver imagens de segurança do estacionamento da padaria, 
talvez queira procurar carros que saíram do estacionamento nesse período.

162|Eugene|2024|7|28|Não sei o nome do ladrão, mas era alguém que eu reconheci. Mais cedo esta manhã,
 antes de chegar à padaria de Emma, ​​eu estava passando pelo caixa eletrônico na Leggett Street e vi 
 o ladrão sacando dinheiro.

163|Raymond|2024|7|28|Quando o ladrão estava saindo da padaria, ele ligou para alguém que falou com ele 
por menos de um minuto. Na ligação, ouvi o ladrão dizer que planejava pegar o primeiro voo de Fiftyville 
amanhã. O ladrão então pediu à pessoa do outro lado da linha para comprar a passagem aérea.

-- ligacoes em 28/07 de menos de um minuto
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60;

221|(130) 555-0289|(996) 555-8899|2024|7|28|51
224|(499) 555-9472|(892) 555-8872|2024|7|28|36
233|(367) 555-5533|(375) 555-8161|2024|7|28|45
251|(499) 555-9472|(717) 555-1342|2024|7|28|50
254|(286) 555-6063|(676) 555-6554|2024|7|28|43
255|(770) 555-1861|(725) 555-3243|2024|7|28|49
261|(031) 555-6622|(910) 555-3251|2024|7|28|38
279|(826) 555-1652|(066) 555-9701|2024|7|28|55
281|(338) 555-6650|(704) 555-2131|2024|7|28|54

-- voos do dia 29/07/2024 - verificar passageiros do voo 36|8|4|2024|7|29|8|20
SELECT * FROM flights 
   WHERE day = 29 AND month = 7 AND year = 2024;

-- passport passageiros 
SELECT passengers.passport_number
   FROM passengers
   JOIN flights ON flights.id = passengers.flight_id
   WHERE flights.day = 29 AND flights.month = 07 AND flights.year = 2024
   AND flights.hour = 8;

7214083635
1695452385
5773159633
1540955065
8294398571
1988161715
9878712108
8496433585

-- pessoas que estavam no voo do dia 29 e fizeram ligacoes no dia 28
SELECT * FROM people
WHERE passport_number IN (7214083635, 1695452385, 5773159633, 1540955065, 
                          8294398571, 1988161715, 9878712108, 8496433585)
AND phone_number IN ('(130) 555-0289', '(499) 555-9472', '(367) 555-5533', 
                     '(286) 555-6063', '(770) 555-1861', '(031) 555-6622',
                     '(826) 555-1652', '(338) 555-6650');

395717|Kenny|(826) 555-1652|9878712108|30G67EN
398010|Sofia|(130) 555-0289|1695452385|G412CB7 
449774|Taylor|(286) 555-6063|1988161715|1106N58 
560886|Kelsey|(499) 555-9472|8294398571|0NTHK55 
686048|Bruce|(367) 555-5533|5773159633|94KL13X

-- logs estacionamento da padaria 10 minutos depois do roubo 10:25am
SELECT * FROM bakery_security_logs
   WHERE day = 28 AND month = 7 AND hour = 10;

264|2024|7|28|10|20|exit|G412CB7
265|2024|7|28|10|21|exit|L93JTIZ
266|2024|7|28|10|23|exit|322W7JE
267|2024|7|28|10|23|exit|0NTHK55
268|2024|7|28|10|35|exit|1106N58

-- pessoas que estavam no voo do dia 29 e fizeram ligacoes no 28 e sairam da padaria proximo do horario do roubo
398010|Sofia|(130) 555-0289|1695452385|G412CB7 
449774|Taylor|(286) 555-6063|1988161715|1106N58 
560886|Kelsey|(499) 555-9472|8294398571|0NTHK55 

-- pessoas que estavam sacando dinheiro na Leggett Street de manha 
ELECT * FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2024 
AND atm_location LIKE 'Leggett Street';

246|28500762|2024|7|28|Leggett Street|withdraw|48
264|28296815|2024|7|28|Leggett Street|withdraw|20
266|76054385|2024|7|28|Leggett Street|withdraw|60
267|49610011|2024|7|28|Leggett Street|withdraw|50
269|16153065|2024|7|28|Leggett Street|withdraw|80
275|86363979|2024|7|28|Leggett Street|deposit|10
288|25506511|2024|7|28|Leggett Street|withdraw|20
313|81061156|2024|7|28|Leggett Street|withdraw|30
336|26013199|2024|7|28|Leggett Street|withdraw|35

-- descobri de quem sao as contas
SELECT * FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE bank_accounts.account_number IN (28500762, 28296815, 76054385, 
                                       49610011, 16153065, 25506511, 
                                       81061156, 26013199);

686048|Bruce|(367) 555-5533|5773159633|94KL13X|49610011|686048|2010
514354|Diana|(770) 555-1861|3592750733|322W7JE|26013199|514354|2012
458378|Brooke|(122) 555-4581|4408372428|QX4YZN3|16153065|458378|2012
395717|Kenny|(826) 555-1652|9878712108|30G67EN|28296815|395717|2014
396669|Iman|(829) 555-5269|7049073643|L93JTIZ|25506511|396669|2014
467400|Luca|(389) 555-5198|8496433585|4328GD8|28500762|467400|2014
449774|Taylor|(286) 555-6063|1988161715|1106N58|76054385|449774|2015 .
438727|Benista|(338) 555-6650|9586786673|8X428L0|81061156|438727|2018

-- para qual cidade taylor foi
