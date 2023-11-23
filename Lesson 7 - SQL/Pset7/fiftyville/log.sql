-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Setting the mode to table for better readability
.mode table -- Investigating the schema
.schema -- First I will see the general structure of the reports
SELECT *
FROM crime_scene_reports
LIMIT 10;
-- Investigating the crime scene reports to see if we can find from from the day of the crime
SELECT *
FROM crime_scene_reports
WHERE day = 28
    AND month = 7;
-- We know that it happened on Humphrey Street.
SELECT *
FROM crime_scene_reports
WHERE day = 28
    AND month = 7
    AND street = 'Humphrey Street';
-- The report with the id 295 is the one that talks about the duck theft
-- Theft of the CS50 duck took place at 10 :15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time – each of their interview 
-- transcripts mentions the bakery.
-- Let us query the interviews that mention the bakery on that day
SELECT transcript
FROM interviews
WHERE transcript LIKE '%bakery%'
    AND day = 28
    AND month = 7;
-- +--------------------------------------------------------------+
-- |                          transcript                          |
-- +--------------------------------------------------------------+
-- | Sometime within ten minutes of the theft, I saw the thief ge | The theft took place at 10:15 am
-- | t into a car in the bakery parking lot and drive away. If yo | Thief left the parking lot within 10 minutes
-- | u have security footage from the bakery parking lot, you mig | This means they left anywhere from 10:15 to 10:25
-- | ht want to look for cars that left the parking lot in that t |
-- | ime frame.                                                   |
-- Let us query the bakery parking lot table to see if there is a car that left the parking lot in that time frame
SELECT *
from bakery_security_logs
WHERE month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25
    AND activity = 'exit';
-- These are all the cars that left in this timespan
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | id  | year | month | day | hour | minute | activity | license_plate |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- | 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
-- | 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
-- | 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
-- | 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
-- | 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
-- | 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
-- | 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
-- | 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
-- +-----+------+-------+-----+------+--------+----------+---------------+
-- +--------------------------------------------------------------+
-- | I don't know the thief's name, but it was someone I recogniz | The thief withdrew money before 10:15 am on that day
-- | ed. Earlier this morning, before I arrived at Emma's bakery, | The atm is on Leggett Street
-- |  I was walking by the ATM on Leggett Street and saw the thie |
-- | f there withdrawing some money.                              |
-- Let us see who withdrew money on that day on Leggett Street before 10:15 am
SELECT *
FROM atm_transactions
WHERE atm_location = 'Leggett Street'
    AND month = 7
    AND day = 28
    AND transaction_type = 'withdraw'
    AND year = 2021;
-- Looks like there is no time for the atm transactions
-- These are the results of the query
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
-- | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
-- | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
-- | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
-- | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- +--------------------------------------------------------------+
-- | As the thief was leaving the bakery, they called someone who | There was a call placed after 10:15 am on that day
-- |  talked to them for less than a minute. In the call, I heard | Shortly after the theft
-- |  the thief say that they were planning to take the earliest  | They planned on taking the first flight from Fiftyville
-- | flight out of Fiftyville tomorrow. The thief then asked the  | Meaning the flight took place on July 29th, 2021
-- | person on the other end of the phone to purchase the flight  | On july 28th, shortly after 10:15 am a ticket was purchased
-- | ticket.                                                      | By the accomplice
-- +--------------------------------------------------------------+
-- Let us check for a call tha took less than a minute
SELECT *
FROM phone_calls
WHERE day = 28
    AND month = 7
    AND duration < 60;
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 221 | (130) 555-0289 | (996) 555-8899 | 2021 | 7     | 28  | 51       |
-- | 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36       |
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
-- | 251 | (499) 555-9472 | (717) 555-1342 | 2021 | 7     | 28  | 50       |
-- | 254 | (286) 555-6063 | (676) 555-6554 | 2021 | 7     | 28  | 43       |
-- | 255 | (770) 555-1861 | (725) 555-3243 | 2021 | 7     | 28  | 49       |
-- | 261 | (031) 555-6622 | (910) 555-3251 | 2021 | 7     | 28  | 38       |
-- | 279 | (826) 555-1652 | (066) 555-9701 | 2021 | 7     | 28  | 55       |
-- | 281 | (338) 555-6650 | (704) 555-2131 | 2021 | 7     | 28  | 54       |
-- Looks like there is no table for purchased tickets
-- Let's query all flights taking place on the 29th and flying from Fiftyville
SELECT *
FROM flights
WHERE day = 29
    AND month = 7
    AND origin_airport_id IN (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    );
-- In the phone call it is mentioned that they would be taking the first flight from Fiftyville
-- Meaning that it must be the flight with id 36
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 18 | 8                 | 6                      | 2021 | 7     | 29  | 16   | 0      |
-- | 23 | 8                 | 11                     | 2021 | 7     | 29  | 12   | 15     |
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
-- | 43 | 8                 | 1                      | 2021 | 7     | 29  | 9    | 30     |
-- | 53 | 8                 | 9                      | 2021 | 7     | 29  | 15   | 20     |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- Let's find out more about the flight taking place at 8:20
SELECT *
FROM flights
WHERE id = 36;
--+----+-------------------+------------------------+------+-------+-----+------+--------+
--| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
--+----+-------------------+------------------------+------+-------+-----+------+--------+
--| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |
--+----+-------------------+------------------------+------+-------+-----+------+--------+
-- Let's see where the destination is
SELECT *
FROM airports
WHERE id = 4;
-- +----+--------------+-------------------+---------------+
-- | id | abbreviation |     full_name     |     city      |
-- +----+--------------+-------------------+---------------+
-- | 4  | LGA          | LaGuardia Airport | New York City |
-- +----+--------------+-------------------+---------------+
-- So the thief flew to NYC
-- Let's find out more about the passengers on this flight
SELECT *
FROM passengers
WHERE flight_id = 36;
-- +-----------+-----------------+------+
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 36        | 7214083635      | 2A   |
-- | 36        | 1695452385      | 3B   |
-- | 36        | 5773159633      | 4A   |
-- | 36        | 1540955065      | 5C   |
-- | 36        | 8294398571      | 6C   |
-- | 36        | 1988161715      | 6D   |
-- | 36        | 9878712108      | 7A   |
-- | 36        | 8496433585      | 7B   |
-- +-----------+-----------------+------+
-- Let's query all of these people that were on the flight
SELECT *
FROM people
WHERE passport_number IN (
        SELECT passport_number
        FROM passengers
        WHERE flight_id = 36
    );
--+--------+--------+----------------+-----------------+---------------+
--|   id   |  name  |  phone_number  | passport_number | license_plate |
--+--------+--------+----------------+-----------------+---------------+
--| 395717 | Kenny  | (826) 555-1652 | 9878712108      | 30G67EN       |
--| 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
--| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
--| 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       |
--| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
--| 651714 | Edward | (328) 555-1152 | 1540955065      | 130LD9Z       |
--| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
--| 953679 | Doris  | (066) 555-9701 | 7214083635      | M51FA04       |
--+--------+--------+----------------+-----------------+---------------+
-- So our suspect must be here, let's see if any of these 
-- license plates match with the leaving cars that morning
SELECT *
FROM people
WHERE license_plate in (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE month = 7
            AND day = 28
            AND hour = 10
            AND minute >= 15
            AND minute <= 25
            AND activity = 'exit'
    );
-- +--------+---------+----------------+-----------------+---------------+
-- |   id   |  name   |  phone_number  | passport_number | license_plate |
-- +--------+---------+----------------+-----------------+---------------+
-- | 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
-- | 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
-- | 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
-- | 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
-- | 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
-- | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+---------+----------------+-----------------+---------------+
-- Let's see if there are any overlapping names
SELECT *
FROM people
WHERE passport_number IN (
        SELECT passport_number
        FROM passengers
        WHERE flight_id = 36
    )
    AND license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE month = 7
            AND day = 28
            AND hour = 10
            AND minute >= 15
            AND minute <= 25
            AND activity = 'exit'
    );
-- These people left the parking lot at the suspected time and where on the same plane to nyc
-- +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
-- | 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+--------+----------------+-----------------+---------------+
-- Let's see if any of them made a phonecall on that fateful day, left the parking lot, and where on the flight
SELECT *
FROM people
WHERE phone_number IN (
        SELECT caller
        FROM phone_calls
        WHERE day = 28
            AND month = 7
            AND duration < 60
    )
    AND passport_number IN (
        SELECT passport_number
        FROM passengers
        WHERE flight_id = 36
    )
    AND license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE month = 7
            AND day = 28
            AND hour = 10
            AND minute >= 15
            AND minute <= 25
            AND activity = 'exit'
    );
-- +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
-- | 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+--------+----------------+-----------------+---------------+
-- These are the 3 people that could be possible suspects
-- Let us not forget about the atm withdrawal, let's check if one of them withdrew money
-- Let's get their bank accounts
SELECT *
FROM bank_accounts
WHERE person_id IN (
        SELECT id
        FROM people
        WHERE phone_number IN (
                SELECT caller
                FROM phone_calls
                WHERE day = 28
                    AND month = 7
                    AND duration < 60
            )
            AND passport_number IN (
                SELECT passport_number
                FROM passengers
                WHERE flight_id = 36
            )
            AND license_plate IN (
                SELECT license_plate
                FROM bakery_security_logs
                WHERE month = 7
                    AND day = 28
                    AND hour = 10
                    AND minute >= 15
                    AND minute <= 25
                    AND activity = 'exit'
            )
    );
-- Looks like only one person has a bank account, made a call on the 28th of July lasting less than a minute,
-- was on the flight to NYC and left the parking lot
-- +----------------+-----------+---------------+
-- | account_number | person_id | creation_year |
-- +----------------+-----------+---------------+
-- | 49610011       | 686048    | 2010          |
-- +----------------+-----------+---------------+
-- Let us check if she withdrew money
SELECT *
FROM atm_transactions
WHERE atm_location = 'Leggett Street'
    AND month = 7
    AND day = 28
    AND transaction_type = 'withdraw'
    AND year = 2021
    AND account_number = 49610011;
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
-- +-----+----------------+------+-------+-----+----------------+------------------+--------+
-- Looks like we have a suspect, let us check who their accomplice is
SELECT *
FROM people
WHERE id IN (
        SELECT person_id
        FROM bank_accounts
        WHERE account_number IN (
                SELECT account_number
                FROM atm_transactions
                WHERE atm_location = 'Leggett Street'
                    AND month = 7
                    AND day = 28
                    AND transaction_type = 'withdraw'
                    AND year = 2021
                    AND account_number = 49610011
            )
    );
-- -- +--------+-------+----------------+-----------------+---------------+
-- |   id   | name  |  phone_number  | passport_number | license_plate |
-- +--------+-------+----------------+-----------------+---------------+
-- | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+-------+----------------+-----------------+---------------+
-- Seems that Bruce is the suspect!!
-- Let us see the person he called
SELECT *
FROM phone_calls
WHERE day = 28
    AND month = 7
    AND duration < 60
    AND caller LIKE '%(367) 555-5533%';
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | id  |     caller     |    receiver    | year | month | day | duration |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- | 233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7     | 28  | 45       |
-- +-----+----------------+----------------+------+-------+-----+----------+
-- Let us find the person who is the receiver
SELECT *
FROM people
WHERE phone_number IN (
        SELECT receiver
        FROM phone_calls
        WHERE day = 28
            AND month = 7
            AND duration < 60
            AND caller LIKE '%(367) 555-5533%'
    );

-- +--------+-------+----------------+-----------------+---------------+
-- |   id   | name  |  phone_number  | passport_number | license_plate |
-- +--------+-------+----------------+-----------------+---------------+
-- | 864400 | Robin | (375) 555-8161 |                 | 4V16VO0       |
-- +--------+-------+----------------+-----------------+---------------+