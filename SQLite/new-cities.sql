
CREATE TABLE new_city
(
    city_name VARCHAR(20) PRIMARY KEY NOT NULL,
    x_coordinate int,
    y_coordinate int
);

INSERT INTO new_city VALUES('Stockholm', 0, 0);
INSERT INTO new_city VALUES('Vienna', 0, 0);


CREATE TABLE new_distance
(
    starting_city VARCHAR(20),
    ending_city   VARCHAR(20),
    kilometers    INT,
    PRIMARY KEY(starting_city, ending_city),
    FOREIGN KEY(starting_city) REFERENCES city(city_name) ON DELETE CASCADE,
    FOREIGN KEY(ending_city) REFERENCES city(city_name) ON DELETE CASCADE
);

INSERT INTO new_distance VALUES ('Amsterdam', 'Stockholm', 1435);
INSERT INTO new_distance VALUES ('Amsterdam', 'Vienna', 1147);
INSERT INTO new_distance VALUES ('Berlin', 'Stockholm', 1084);
INSERT INTO new_distance VALUES ('Berlin', 'Vienna', 640);
INSERT INTO new_distance VALUES ('Brussels', 'Stockholm', 1564);
INSERT INTO new_distance VALUES ('Brussels', 'Vienna', 1104);
INSERT INTO new_distance VALUES ('Budapest', 'Stockholm', 1951);
INSERT INTO new_distance VALUES ('Budapest', 'Vienna', 243);
INSERT INTO new_distance VALUES ('Hamburg', 'Stockholm', 1079);
INSERT INTO new_distance VALUES ('Hamburg', 'Vienna', 930);
INSERT INTO new_distance VALUES ('Lisbon', 'Stockholm', 3610);
INSERT INTO new_distance VALUES ('Lisbon', 'Vienna', 2867);
INSERT INTO new_distance VALUES ('London', 'Stockholm', 1902);
INSERT INTO new_distance VALUES ('London', 'Vienna', 1461);
INSERT INTO new_distance VALUES ('Madrid', 'Stockholm', 3141);
INSERT INTO new_distance VALUES ('Madrid', 'Vienna', 2401);
INSERT INTO new_distance VALUES ('Paris', 'Stockholm', 1885);
INSERT INTO new_distance VALUES ('Paris', 'Vienna', 1236);
INSERT INTO new_distance VALUES ('Prague', 'Stockholm', 1428);
INSERT INTO new_distance VALUES ('Prague', 'Vienna', 331);
INSERT INTO new_distance VALUES ('Rome', 'Stockholm', 2546);
INSERT INTO new_distance VALUES ('Rome', 'Vienna', 1120);
INSERT INTO new_distance VALUES ('Stockholm', 'Amsterdam', 1435);
INSERT INTO new_distance VALUES ('Stockholm', 'Berlin', 1084);
INSERT INTO new_distance VALUES ('Stockholm', 'Brussels', 1564);
INSERT INTO new_distance VALUES ('Stockholm', 'Budapest', 1951);
INSERT INTO new_distance VALUES ('Stockholm', 'Hamburg', 1079);
INSERT INTO new_distance VALUES ('Stockholm', 'Lisbon', 3610);
INSERT INTO new_distance VALUES ('Stockholm', 'London', 1902);
INSERT INTO new_distance VALUES ('Stockholm', 'Madrid', 3141);
INSERT INTO new_distance VALUES ('Stockholm', 'Paris', 1885);
INSERT INTO new_distance VALUES ('Stockholm', 'Prague', 1428);
INSERT INTO new_distance VALUES ('Stockholm', 'Rome', 2546);
INSERT INTO new_distance VALUES ('Stockholm', 'Vienna', 1758);
INSERT INTO new_distance VALUES ('Vienna', 'Amsterdam', 1147);
INSERT INTO new_distance VALUES ('Vienna', 'Berlin', 640);
INSERT INTO new_distance VALUES ('Vienna', 'Brussels', 1104);
INSERT INTO new_distance VALUES ('Vienna', 'Budapest', 243);
INSERT INTO new_distance VALUES ('Vienna', 'Hamburg', 930);
INSERT INTO new_distance VALUES ('Vienna', 'Lisbon', 2867);
INSERT INTO new_distance VALUES ('Vienna', 'London', 1461);
INSERT INTO new_distance VALUES ('Vienna', 'Madrid', 2401);
INSERT INTO new_distance VALUES ('Vienna', 'Paris', 1236);
INSERT INTO new_distance VALUES ('Vienna', 'Prague', 331);
INSERT INTO new_distance VALUES ('Vienna', 'Rome', 1120);
INSERT INTO new_distance VALUES ('Vienna', 'Stockholm', 1758);

CREATE TABLE new_food
(
    food_name VARCHAR(40) PRIMARY KEY,
    cost DECIMAL(4, 2) DEFAULT 0.00,
    city_name VARCHAR(20) NOT NULL,
    FOREIGN KEY(city_name) REFERENCES city(city_name) ON DELETE CASCADE
);

-- Stockholm
INSERT INTO new_food VALUES('Raggmunk', 6.75, 'Stockholm');
INSERT INTO new_food VALUES('Gravad lax ', 13.76, 'Stockholm');
INSERT INTO new_food VALUES('husmanskost', 7.98, 'Stockholm');
-- Vienna
INSERT INTO new_food VALUES('Wiener Schnitzel', 4.94, 'Vienna');
INSERT INTO new_food VALUES('Kaiserschmarrn', 7.53, 'Vienna');
INSERT INTO new_food VALUES('Sachertorte', 5.85, 'Vienna');
