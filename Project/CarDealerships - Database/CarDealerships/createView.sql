SET SCHEMA FN71958;

CREATE VIEW SHOW_CARS
AS SELECT *
FROM CARS
WHERE BASE_PRICE <= 200000;

SELECT * FROM SHOW_CARS;

CREATE VIEW SHOW_CARS_CLIENTS
AS SELECT C.NAME AS NAME, C.CAR AS CAR, C.SERVICE_HISTORY AS SERVICE_HISTORY
FROM CLIENTS C
WHERE CAR IS NOT NULL AND C.SERVICE_HISTORY IS NOT NULL;

SELECT * FROM SHOW_CARS_CLIENTS;

CREATE VIEW SHOW_CLIENTS
AS SELECT C.NAME AS NAME, C.PHONE AS PHONE, CS.MODEL AS MODEL_CAR, U.KIND_SERVICE AS KIND_SERVICE
FROM CLIENTS C, BUY B, USE U, CARS CS
WHERE C.PHONE = B.PHONE_CLIENT AND C.PHONE = U.PHONE_CLIENT AND B.VIN = CS.VIN;

SELECT * FROM SHOW_CLIENTS;