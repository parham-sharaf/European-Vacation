<<<<<<< HEAD
CREATE TABLE city
(
    city_name VARCHAR(20) PRIMARY KEY NOT NULL,
    x_coordinate int,
    y_coordinate int
);

INSERT INTO city VALUES('Amsterdam', 440, 640);
INSERT INTO city VALUES('Berlin', 605, 650);
INSERT INTO city VALUES('Brussels', 430, 685);
INSERT INTO city VALUES('Budapest', 730, 800);
INSERT INTO city VALUES('Hamburg', 540, 610);
INSERT INTO city VALUES('Lisbon', 50, 980);
INSERT INTO city VALUES('London', 350, 648);
INSERT INTO city VALUES('Madrid', 200, 950);
INSERT INTO city VALUES('Paris', 390, 735);
INSERT INTO city VALUES('Prague', 625, 720);
INSERT INTO city VALUES('Rome', 550, 950);

CREATE TABLE distance
(
    starting_city VARCHAR(20),
    ending_city   VARCHAR(20),
    kilometers    INT,
    PRIMARY KEY(starting_city, ending_city),
    FOREIGN KEY(starting_city) REFERENCES city(city_name) ON DELETE CASCADE,
    FOREIGN KEY(ending_city) REFERENCES city(city_name) ON DELETE CASCADE
);

INSERT INTO distance VALUES('Amsterdam', 'Berlin', 655);
INSERT INTO distance VALUES('Amsterdam', 'Brussels', 236);
INSERT INTO distance VALUES('Amsterdam', 'Budapest', 1395);
INSERT INTO distance VALUES('Amsterdam', 'Hamburg', 361);
INSERT INTO distance VALUES('Amsterdam', 'Lisbon', 2236);
INSERT INTO distance VALUES('Amsterdam', 'London', 541);
INSERT INTO distance VALUES('Amsterdam', 'Madrid', 1767);
INSERT INTO distance VALUES('Amsterdam', 'Paris', 430);
INSERT INTO distance VALUES('Amsterdam', 'Prague', 878);
INSERT INTO distance VALUES('Amsterdam', 'Rome', 1647);
INSERT INTO distance VALUES('Berlin', 'Amsterdam', 655);
INSERT INTO distance VALUES('Berlin', 'Brussels', 765);
INSERT INTO distance VALUES('Berlin', 'Budapest', 873);
INSERT INTO distance VALUES('Berlin', 'Hamburg', 288);
INSERT INTO distance VALUES('Berlin', 'Lisbon', 2779);
INSERT INTO distance VALUES('Berlin', 'London', 678);
INSERT INTO distance VALUES('Berlin', 'Madrid', 2392);
INSERT INTO distance VALUES('Berlin', 'Paris', 1054);
INSERT INTO distance VALUES('Berlin', 'Prague', 349);
INSERT INTO distance VALUES('Berlin', 'Rome', 1502);
INSERT INTO distance VALUES('Brussels', 'Amsterdam', 236);
INSERT INTO distance VALUES('Brussels', 'Berlin', 765);
INSERT INTO distance VALUES('Brussels', 'Budapest', 1353);
INSERT INTO distance VALUES('Brussels', 'Hamburg', 489);
INSERT INTO distance VALUES('Brussels', 'Lisbon', 2357);
INSERT INTO distance VALUES('Brussels', 'London', 403);
INSERT INTO distance VALUES('Brussels', 'Madrid', 1578);
INSERT INTO distance VALUES('Brussels', 'Paris', 313);
INSERT INTO distance VALUES('Brussels', 'Prague', 898);
INSERT INTO distance VALUES('Brussels', 'Rome', 1483);
INSERT INTO distance VALUES('Budapest', 'Amsterdam', 1395);
INSERT INTO distance VALUES('Budapest', 'Berlin', 873);
INSERT INTO distance VALUES('Budapest', 'Brussels', 1353);
INSERT INTO distance VALUES('Budapest', 'Hamburg', 1163);
INSERT INTO distance VALUES('Budapest', 'Lisbon', 3069);
INSERT INTO distance VALUES('Budapest', 'London', 1707);
INSERT INTO distance VALUES('Budapest', 'Madrid', 2512);
INSERT INTO distance VALUES('Budapest', 'Paris', 1485);
INSERT INTO distance VALUES('Budapest', 'Prague', 525);
INSERT INTO distance VALUES('Budapest', 'Rome', 1274);
INSERT INTO distance VALUES('Hamburg', 'Amsterdam', 361);
INSERT INTO distance VALUES('Hamburg', 'Berlin', 288);
INSERT INTO distance VALUES('Hamburg', 'Brussels', 489);
INSERT INTO distance VALUES('Hamburg', 'Budapest', 1163);
INSERT INTO distance VALUES('Hamburg', 'Lisbon', 2121);
INSERT INTO distance VALUES('Hamburg', 'London', 930);
INSERT INTO distance VALUES('Hamburg', 'Madrid', 2171);
INSERT INTO distance VALUES('Hamburg', 'Paris', 376);
INSERT INTO distance VALUES('Hamburg', 'Prague', 640);
INSERT INTO distance VALUES('Hamburg', 'Rome', 1658);
INSERT INTO distance VALUES('Lisbon', 'Amsterdam', 2236);
INSERT INTO distance VALUES('Lisbon', 'Berlin', 2779);
INSERT INTO distance VALUES('Lisbon', 'Brussels', 2357);
INSERT INTO distance VALUES('Lisbon', 'Budapest', 3069);
INSERT INTO distance VALUES('Lisbon', 'Hamburg', 2121);
INSERT INTO distance VALUES('Lisbon', 'London', 2189);
INSERT INTO distance VALUES('Lisbon', 'Madrid', 625);
INSERT INTO distance VALUES('Lisbon', 'Paris', 1736);
INSERT INTO distance VALUES('Lisbon', 'Prague', 2707);
INSERT INTO distance VALUES('Lisbon', 'Rome', 2510);
INSERT INTO distance VALUES('London', 'Amsterdam', 541);
INSERT INTO distance VALUES('London', 'Berlin', 678);
INSERT INTO distance VALUES('London', 'Brussels', 403);
INSERT INTO distance VALUES('London', 'Budapest', 1707);
INSERT INTO distance VALUES('London', 'Hamburg', 930);
INSERT INTO distance VALUES('London', 'Lisbon', 2189);
INSERT INTO distance VALUES('London', 'Madrid', 1719);
INSERT INTO distance VALUES('London', 'Paris', 464);
INSERT INTO distance VALUES('London', 'Prague', 1265);
INSERT INTO distance VALUES('London', 'Rome', 1866);
INSERT INTO distance VALUES('Madrid', 'Amsterdam', 1767);
INSERT INTO distance VALUES('Madrid', 'Berlin', 2392);
INSERT INTO distance VALUES('Madrid', 'Brussels', 1578);
INSERT INTO distance VALUES('Madrid', 'Budapest', 2512);
INSERT INTO distance VALUES('Madrid', 'Hamburg', 2171);
INSERT INTO distance VALUES('Madrid', 'Lisbon', 625);
INSERT INTO distance VALUES('Madrid', 'London', 1719);
INSERT INTO distance VALUES('Madrid', 'Paris', 1633);
INSERT INTO distance VALUES('Madrid', 'Prague', 2312);
INSERT INTO distance VALUES('Madrid', 'Rome', 1951);
INSERT INTO distance VALUES('Paris', 'Amsterdam', 430);
INSERT INTO distance VALUES('Paris', 'Berlin', 1054);
INSERT INTO distance VALUES('Paris', 'Brussels', 313);
INSERT INTO distance VALUES('Paris', 'Budapest', 1485);
INSERT INTO distance VALUES('Paris', 'Hamburg', 376);
INSERT INTO distance VALUES('Paris', 'Lisbon', 1736);
INSERT INTO distance VALUES('Paris', 'London', 464);
INSERT INTO distance VALUES('Paris', 'Madrid', 1633);
INSERT INTO distance VALUES('Paris', 'Prague', 1030);
INSERT INTO distance VALUES('Paris', 'Rome', 1442);
INSERT INTO distance VALUES('Prague', 'Amsterdam', 878);
INSERT INTO distance VALUES('Prague', 'Berlin', 349);
INSERT INTO distance VALUES('Prague', 'Brussels', 898);
INSERT INTO distance VALUES('Prague', 'Budapest', 525);
INSERT INTO distance VALUES('Prague', 'Hamburg', 640);
INSERT INTO distance VALUES('Prague', 'Lisbon', 2707);
INSERT INTO distance VALUES('Prague', 'London', 1265);
INSERT INTO distance VALUES('Prague', 'Madrid', 2312);
INSERT INTO distance VALUES('Prague', 'Paris', 1030);
INSERT INTO distance VALUES('Prague', 'Rome', 1303);
INSERT INTO distance VALUES('Rome', 'Amsterdam', 1647);
INSERT INTO distance VALUES('Rome', 'Berlin', 1502);
INSERT INTO distance VALUES('Rome', 'Brussels', 1483);
INSERT INTO distance VALUES('Rome', 'Budapest', 1274);
INSERT INTO distance VALUES('Rome', 'Hamburg', 1658);
INSERT INTO distance VALUES('Rome', 'Lisbon', 2510);
INSERT INTO distance VALUES('Rome', 'London', 1866);
INSERT INTO distance VALUES('Rome', 'Madrid', 1951);
INSERT INTO distance VALUES('Rome', 'Paris', 1442);
INSERT INTO distance VALUES('Rome', 'Prague', 1303);


CREATE TABLE food
(
    food_name VARCHAR(40) PRIMARY KEY,
    cost DECIMAL(4, 2) DEFAULT 0.00,
    city_name VARCHAR(20) NOT NULL,
    FOREIGN KEY(city_name) REFERENCES city(city_name) ON DELETE CASCADE
);

-- Amsterdam
INSERT INTO food VALUES('Stroopwafel', 5.76, 'Amsterdam');
INSERT INTO food VALUES('Thick Dutch fries', 3.21, 'Amsterdam');
INSERT INTO food VALUES('Kibbeling', 8.65, 'Amsterdam');
-- Berlin
INSERT INTO food VALUES('Pretzels', 4.00, 'Berlin');
INSERT INTO food VALUES('Apfelstrudel', 6.25, 'Berlin');
INSERT INTO food VALUES('Berliner Pfannkuche', 8.23, 'Berlin');
INSERT INTO food VALUES('Schnitzel', 9.79, 'Berlin');
-- Brussels
INSERT INTO food VALUES('Waterzooi', 6.45, 'Brussels');
INSERT INTO food VALUES('Luikse Siroop', 4.98, 'Brussels');
INSERT INTO food VALUES('Mosselen-friet', 4.45, 'Brussels');
INSERT INTO food VALUES('Speculoos', 2.79, 'Brussels');
-- Budapest
INSERT INTO food VALUES('Goulash', 8.43, 'Budapest');
INSERT INTO food VALUES('Stuffed cabbage', 6.99, 'Budapest');
INSERT INTO food VALUES('Smoked meat', 12.99, 'Budapest');
INSERT INTO food VALUES('Dobos torta', 2.79, 'Budapest');
-- Hamburg
INSERT INTO food VALUES('Hamburger Hummersuppe', 6.46, 'Hamburg');
INSERT INTO food VALUES('Knackwurst', 2.79, 'Hamburg');
INSERT INTO food VALUES('Krabbentoast ', 2.79, 'Hamburg');
INSERT INTO food VALUES('Franzbrötchen', 2.79, 'Hamburg');
-- Lisbon
INSERT INTO food VALUES('Bacalhau', 5.49, 'Lisbon');
INSERT INTO food VALUES('Caldeirada', 7.63, 'Lisbon');
INSERT INTO food VALUES('Alcatra', 18.66, 'Lisbon');
-- London
INSERT INTO food VALUES('Yorkshire Pudding', 3.49, 'London');
INSERT INTO food VALUES('Bangers and Mash', 6.63, 'London');
INSERT INTO food VALUES('Sticky Toffee Pudding', 5.66, 'London');
-- Madrid
INSERT INTO food VALUES('Bocata de calamares', 6.96, 'Madrid');
INSERT INTO food VALUES('Oreja a la plancha', 11.85, 'Madrid');
INSERT INTO food VALUES('Caracoles a la madrileña', 6.94, 'Madrid');
-- Paris
INSERT INTO food VALUES('Caramels', 4.76, 'Paris');
INSERT INTO food VALUES('Bordier Butter', 5.65, 'Paris');
INSERT INTO food VALUES('Baguette ', 4.99, 'Paris');
INSERT INTO food VALUES('Pain au Chocolat ', 4.69, 'Paris');
-- Prague
INSERT INTO food VALUES('Beef steak tartare', 18.76, 'Prague');
INSERT INTO food VALUES('Kulajda', 6.89, 'Prague');
INSERT INTO food VALUES('Svickova', 5.98, 'Prague');
INSERT INTO food VALUES('Roast duck', 14.69, 'Prague');
-- Rome
INSERT INTO food VALUES('Spaghetti alla Carbonara', 6.73, 'Rome');
INSERT INTO food VALUES('Bruschetta', 4.85, 'Rome');
INSERT INTO food VALUES('Scaloppine', 12.99, 'Rome');
INSERT INTO food VALUES('Rigatoni con la Pajata', 8.79, 'Rome');
=======
CREATE TABLE city
(
    city_name VARCHAR(20) PRIMARY KEY NOT NULL,
    x_coordinate int,
    y_coordinate int
);

INSERT INTO city VALUES('Amsterdam', 440, 640);
INSERT INTO city VALUES('Berlin', 605, 650);
INSERT INTO city VALUES('Brussels', 430, 685);
INSERT INTO city VALUES('Budapest', 730, 800);
INSERT INTO city VALUES('Hamburg', 540, 610);
INSERT INTO city VALUES('Lisbon', 50, 980);
INSERT INTO city VALUES('London', 350, 648);
INSERT INTO city VALUES('Madrid', 200, 950);
INSERT INTO city VALUES('Paris', 390, 735);
INSERT INTO city VALUES('Prague', 625, 720);
INSERT INTO city VALUES('Rome', 550, 950);

CREATE TABLE distance
(
    starting_city VARCHAR(20),
    ending_city   VARCHAR(20),
    kilometers    INT,
    PRIMARY KEY(starting_city, ending_city),
    FOREIGN KEY(starting_city) REFERENCES city(city_name) ON DELETE CASCADE,
    FOREIGN KEY(ending_city) REFERENCES city(city_name) ON DELETE CASCADE
);

INSERT INTO distance VALUES('Amsterdam', 'Berlin', 655);
INSERT INTO distance VALUES('Amsterdam', 'Brussels', 236);
INSERT INTO distance VALUES('Amsterdam', 'Budapest', 1395);
INSERT INTO distance VALUES('Amsterdam', 'Hamburg', 361);
INSERT INTO distance VALUES('Amsterdam', 'Lisbon', 2236);
INSERT INTO distance VALUES('Amsterdam', 'London', 541);
INSERT INTO distance VALUES('Amsterdam', 'Madrid', 1767);
INSERT INTO distance VALUES('Amsterdam', 'Paris', 430);
INSERT INTO distance VALUES('Amsterdam', 'Prague', 878);
INSERT INTO distance VALUES('Amsterdam', 'Rome', 1647);
INSERT INTO distance VALUES('Berlin', 'Amsterdam', 655);
INSERT INTO distance VALUES('Berlin', 'Brussels', 765);
INSERT INTO distance VALUES('Berlin', 'Budapest', 873);
INSERT INTO distance VALUES('Berlin', 'Hamburg', 288);
INSERT INTO distance VALUES('Berlin', 'Lisbon', 2779);
INSERT INTO distance VALUES('Berlin', 'London', 678);
INSERT INTO distance VALUES('Berlin', 'Madrid', 2392);
INSERT INTO distance VALUES('Berlin', 'Paris', 1054);
INSERT INTO distance VALUES('Berlin', 'Prague', 349);
INSERT INTO distance VALUES('Berlin', 'Rome', 1502);
INSERT INTO distance VALUES('Brussels', 'Amsterdam', 236);
INSERT INTO distance VALUES('Brussels', 'Berlin', 765);
INSERT INTO distance VALUES('Brussels', 'Budapest', 1353);
INSERT INTO distance VALUES('Brussels', 'Hamburg', 489);
INSERT INTO distance VALUES('Brussels', 'Lisbon', 2357);
INSERT INTO distance VALUES('Brussels', 'London', 403);
INSERT INTO distance VALUES('Brussels', 'Madrid', 1578);
INSERT INTO distance VALUES('Brussels', 'Paris', 313);
INSERT INTO distance VALUES('Brussels', 'Prague', 898);
INSERT INTO distance VALUES('Brussels', 'Rome', 1483);
INSERT INTO distance VALUES('Budapest', 'Amsterdam', 1395);
INSERT INTO distance VALUES('Budapest', 'Berlin', 873);
INSERT INTO distance VALUES('Budapest', 'Brussels', 1353);
INSERT INTO distance VALUES('Budapest', 'Hamburg', 1163);
INSERT INTO distance VALUES('Budapest', 'Lisbon', 3069);
INSERT INTO distance VALUES('Budapest', 'London', 1707);
INSERT INTO distance VALUES('Budapest', 'Madrid', 2512);
INSERT INTO distance VALUES('Budapest', 'Paris', 1485);
INSERT INTO distance VALUES('Budapest', 'Prague', 525);
INSERT INTO distance VALUES('Budapest', 'Rome', 1274);
INSERT INTO distance VALUES('Hamburg', 'Amsterdam', 361);
INSERT INTO distance VALUES('Hamburg', 'Berlin', 288);
INSERT INTO distance VALUES('Hamburg', 'Brussels', 489);
INSERT INTO distance VALUES('Hamburg', 'Budapest', 1163);
INSERT INTO distance VALUES('Hamburg', 'Lisbon', 2121);
INSERT INTO distance VALUES('Hamburg', 'London', 930);
INSERT INTO distance VALUES('Hamburg', 'Madrid', 2171);
INSERT INTO distance VALUES('Hamburg', 'Paris', 376);
INSERT INTO distance VALUES('Hamburg', 'Prague', 640);
INSERT INTO distance VALUES('Hamburg', 'Rome', 1658);
INSERT INTO distance VALUES('Lisbon', 'Amsterdam', 2236);
INSERT INTO distance VALUES('Lisbon', 'Berlin', 2779);
INSERT INTO distance VALUES('Lisbon', 'Brussels', 2357);
INSERT INTO distance VALUES('Lisbon', 'Budapest', 3069);
INSERT INTO distance VALUES('Lisbon', 'Hamburg', 2121);
INSERT INTO distance VALUES('Lisbon', 'London', 2189);
INSERT INTO distance VALUES('Lisbon', 'Madrid', 625);
INSERT INTO distance VALUES('Lisbon', 'Paris', 1736);
INSERT INTO distance VALUES('Lisbon', 'Prague', 2707);
INSERT INTO distance VALUES('Lisbon', 'Rome', 2510);
INSERT INTO distance VALUES('London', 'Amsterdam', 541);
INSERT INTO distance VALUES('London', 'Berlin', 678);
INSERT INTO distance VALUES('London', 'Brussels', 403);
INSERT INTO distance VALUES('London', 'Budapest', 1707);
INSERT INTO distance VALUES('London', 'Hamburg', 930);
INSERT INTO distance VALUES('London', 'Lisbon', 2189);
INSERT INTO distance VALUES('London', 'Madrid', 1719);
INSERT INTO distance VALUES('London', 'Paris', 464);
INSERT INTO distance VALUES('London', 'Prague', 1265);
INSERT INTO distance VALUES('London', 'Rome', 1866);
INSERT INTO distance VALUES('Madrid', 'Amsterdam', 1767);
INSERT INTO distance VALUES('Madrid', 'Berlin', 2392);
INSERT INTO distance VALUES('Madrid', 'Brussels', 1578);
INSERT INTO distance VALUES('Madrid', 'Budapest', 2512);
INSERT INTO distance VALUES('Madrid', 'Hamburg', 2171);
INSERT INTO distance VALUES('Madrid', 'Lisbon', 625);
INSERT INTO distance VALUES('Madrid', 'London', 1719);
INSERT INTO distance VALUES('Madrid', 'Paris', 1633);
INSERT INTO distance VALUES('Madrid', 'Prague', 2312);
INSERT INTO distance VALUES('Madrid', 'Rome', 1951);
INSERT INTO distance VALUES('Paris', 'Amsterdam', 430);
INSERT INTO distance VALUES('Paris', 'Berlin', 1054);
INSERT INTO distance VALUES('Paris', 'Brussels', 313);
INSERT INTO distance VALUES('Paris', 'Budapest', 1485);
INSERT INTO distance VALUES('Paris', 'Hamburg', 376);
INSERT INTO distance VALUES('Paris', 'Lisbon', 1736);
INSERT INTO distance VALUES('Paris', 'London', 464);
INSERT INTO distance VALUES('Paris', 'Madrid', 1633);
INSERT INTO distance VALUES('Paris', 'Prague', 1030);
INSERT INTO distance VALUES('Paris', 'Rome', 1442);
INSERT INTO distance VALUES('Prague', 'Amsterdam', 878);
INSERT INTO distance VALUES('Prague', 'Berlin', 349);
INSERT INTO distance VALUES('Prague', 'Brussels', 898);
INSERT INTO distance VALUES('Prague', 'Budapest', 525);
INSERT INTO distance VALUES('Prague', 'Hamburg', 640);
INSERT INTO distance VALUES('Prague', 'Lisbon', 2707);
INSERT INTO distance VALUES('Prague', 'London', 1265);
INSERT INTO distance VALUES('Prague', 'Madrid', 2312);
INSERT INTO distance VALUES('Prague', 'Paris', 1030);
INSERT INTO distance VALUES('Prague', 'Rome', 1303);
INSERT INTO distance VALUES('Rome', 'Amsterdam', 1647);
INSERT INTO distance VALUES('Rome', 'Berlin', 1502);
INSERT INTO distance VALUES('Rome', 'Brussels', 1483);
INSERT INTO distance VALUES('Rome', 'Budapest', 1274);
INSERT INTO distance VALUES('Rome', 'Hamburg', 1658);
INSERT INTO distance VALUES('Rome', 'Lisbon', 2510);
INSERT INTO distance VALUES('Rome', 'London', 1866);
INSERT INTO distance VALUES('Rome', 'Madrid', 1951);
INSERT INTO distance VALUES('Rome', 'Paris', 1442);
INSERT INTO distance VALUES('Rome', 'Prague', 1303);


CREATE TABLE food
(
    food_name VARCHAR(40) PRIMARY KEY,
    cost DECIMAL(4, 2) DEFAULT 0.00,
    city_name VARCHAR(20) NOT NULL,
    FOREIGN KEY(city_name) REFERENCES city(city_name) ON DELETE CASCADE
);

-- Amsterdam
INSERT INTO food VALUES('Stroopwafel', 5.76, 'Amsterdam');
INSERT INTO food VALUES('Thick Dutch fries', 3.21, 'Amsterdam');
INSERT INTO food VALUES('Kibbeling', 8.65, 'Amsterdam');
-- Berlin
INSERT INTO food VALUES('Pretzels', 4.00, 'Berlin');
INSERT INTO food VALUES('Apfelstrudel', 6.25, 'Berlin');
INSERT INTO food VALUES('Berliner Pfannkuche', 8.23, 'Berlin');
INSERT INTO food VALUES('Schnitzel', 9.79, 'Berlin');
-- Brussels
INSERT INTO food VALUES('Waterzooi', 6.45, 'Brussels');
INSERT INTO food VALUES('Luikse Siroop', 4.98, 'Brussels');
INSERT INTO food VALUES('Mosselen-friet', 4.45, 'Brussels');
INSERT INTO food VALUES('Speculoos', 2.79, 'Brussels');
-- Budapest
INSERT INTO food VALUES('Goulash', 8.43, 'Budapest');
INSERT INTO food VALUES('Stuffed cabbage', 6.99, 'Budapest');
INSERT INTO food VALUES('Smoked meat', 12.99, 'Budapest');
INSERT INTO food VALUES('Dobos torta', 2.79, 'Budapest');
-- Hamburg
INSERT INTO food VALUES('Hamburger Hummersuppe', 6.46, 'Hamburg');
INSERT INTO food VALUES('Knackwurst', 2.79, 'Hamburg');
INSERT INTO food VALUES('Krabbentoast ', 2.79, 'Hamburg');
INSERT INTO food VALUES('Franzbrötchen', 2.79, 'Hamburg');
-- Lisbon
INSERT INTO food VALUES('Bacalhau', 5.49, 'Lisbon');
INSERT INTO food VALUES('Caldeirada', 7.63, 'Lisbon');
INSERT INTO food VALUES('Alcatra', 18.66, 'Lisbon');
-- London
INSERT INTO food VALUES('Yorkshire Pudding', 3.49, 'London');
INSERT INTO food VALUES('Bangers and Mash', 6.63, 'London');
INSERT INTO food VALUES('Sticky Toffee Pudding', 5.66, 'London');
-- Madrid
INSERT INTO food VALUES('Bocata de calamares', 6.96, 'Madrid');
INSERT INTO food VALUES('Oreja a la plancha', 11.85, 'Madrid');
INSERT INTO food VALUES('Caracoles a la madrileña', 6.94, 'Madrid');
-- Paris
INSERT INTO food VALUES('Caramels', 4.76, 'Paris');
INSERT INTO food VALUES('Bordier Butter', 5.65, 'Paris');
INSERT INTO food VALUES('Baguette ', 4.99, 'Paris');
INSERT INTO food VALUES('Pain au Chocolat ', 4.69, 'Paris');
-- Prague
INSERT INTO food VALUES('Beef steak tartare', 18.76, 'Prague');
INSERT INTO food VALUES('Kulajda', 6.89, 'Prague');
INSERT INTO food VALUES('Svickova', 5.98, 'Prague');
INSERT INTO food VALUES('Roast duck', 14.69, 'Prague');
-- Rome
INSERT INTO food VALUES('Spaghetti alla Carbonara', 6.73, 'Rome');
INSERT INTO food VALUES('Bruschetta', 4.85, 'Rome');
INSERT INTO food VALUES('Scaloppine', 12.99, 'Rome');
INSERT INTO food VALUES('Rigatoni con la Pajata', 8.79, 'Rome');
>>>>>>> UI
INSERT INTO food VALUES('Carciofi alla giudia', 15.99, 'Rome');