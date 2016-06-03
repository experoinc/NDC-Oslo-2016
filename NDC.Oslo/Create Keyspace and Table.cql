CREATE KEYSPACE ndc_oslo WITH replication = {'class': 'SimpleStrategy', 
'replication_factor': '1'};

USE ndc_oslo;

CREATE TABLE location_by_tripid (
    truckname text,
    manufacturer text,
    tripid text,
    time timestamp,
    latitude float,
    longitude float,
    PRIMARY KEY ((truckname, manufacturer, tripid), time)
) WITH CLUSTERING ORDER BY (time DESC)