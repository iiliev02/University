SET SCHEMA FN71958;

CREATE OR REPLACE PROCEDURE MODIFICATIONSCAR(IN vin_p char(17))
LANGUAGE SQL
BEGIN
    DECLARE modification_info ANCHOR ROW HAS;
    DECLARE cnt INTEGER DEFAULT 0;
    DECLARE count_modification INTEGER DEFAULT 0;
    DECLARE cursor1 CURSOR FOR SELECT * FROM HAS
    WHERE VIN = vin_p;

    SELECT COUNT(*) INTO count_modification FROM HAS WHERE VIN = vin_p;

    OPEN cursor1;
    WHILE cnt < count_modification DO
        SET cnt = cnt + 1;
        FETCH cursor1 INTO modification_info;
        CALL DBMS_OUTPUT.PUT_LINE('Name of modification: ' || modification_info.KIND_MODIFICATION);
    END WHILE;
    CLOSE cursor1;
END;

CREATE OR REPLACE PROCEDURE COUNTCARSWITHMODIFICATION(IN v_modification char(50), OUT cnt_p INT)
LANGUAGE SQL
BEGIN
    DECLARE modification_info ANCHOR ROW MODIFICATIONS;
    DECLARE count_cars INTEGER DEFAULT 0;
    DECLARE cursor1 CURSOR FOR SELECT * FROM MODIFICATIONS WHERE KIND_MODIFICATION = v_modification;

    SELECT COUNT(*) INTO count_cars FROM HAS WHERE KIND_MODIFICATION = v_modification;
    SET cnt_p = count_cars;

    OPEN cursor1;
    FETCH cursor1 INTO modification_info;
    CALL DBMS_OUTPUT.PUT_LINE(' Name of modification: ' || modification_info.KIND_MODIFICATION ||
                              ' with price: ' || modification_info.PRICE);
    CLOSE cursor1;

END;

CREATE OR REPLACE PROCEDURE CARINFORMATION(IN vin_p char(17))
LANGUAGE SQL
BEGIN
    DECLARE car_info ANCHOR ROW CARS;
    DECLARE cursor1 CURSOR FOR SELECT * FROM CARS WHERE VIN = vin_p;

    OPEN cursor1;
    FETCH cursor1 INTO car_info;
    CALL DBMS_OUTPUT.PUT_LINE('VIN: ' || car_info.VIN ||
                              ' Model: ' || car_info.MODEL ||
                              ' Engine: ' || car_info.ENGINE ||
                              ' Transmission: ' || car_info.TRANSMISSION);
    CLOSE cursor1;

END;

CREATE OR REPLACE PROCEDURE SHOWCARS(IN v_namedealership char(50))
LANGUAGE SQL
BEGIN
    DECLARE owns_info ANCHOR ROW OWNS;
    DECLARE count_cars INTEGER DEFAULT 0;
    DECLARE cnt INTEGER DEFAULT 0;
    DECLARE exist_showroom INTEGER DEFAULT 0;
    DECLARE R INT;
    DECLARE cursor1 CURSOR FOR SELECT * FROM OWNS WHERE CAR_DEALERSHIP_NAME = v_namedealership;

    SELECT COUNT(*) INTO exist_showroom FROM CARDEALERSHIPS WHERE NAME = v_namedealership;
    SELECT COUNT(*) INTO count_cars FROM OWNS WHERE CAR_DEALERSHIP_NAME = v_namedealership;

    IF exist_showroom = 0 THEN
        SET R = RAISE_ERROR('70001', 'This showroom does not exist.');
    END IF;

    OPEN cursor1;
    WHILE cnt < count_cars DO
        SET cnt = cnt + 1;
        FETCH cursor1 INTO owns_info;
        CALL FN71958.CARINFORMATION(owns_info.VIN);
    END WHILE;
    CLOSE cursor1;
END;

CALL FN71958.MODIFICATIONSCAR('WDBGA51E4TA328716');
CALL FN71958.COUNTCARSWITHMODIFICATION('AMG Pack - Exterior & Interior');
CALL FN71958.SHOWCARS('Mercedes - Varna');