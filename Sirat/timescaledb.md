
### TimescaleDB 
# what is time series data?

tracks change over time,records have a timestamp and observation.

stock price, CPU and memory isage, sensor data,ad views, COVID-19
can be captured at regular intervals(metrics) or irregular intervals (events)

immutability, ordered, appends-only (insert)

events whose value increases when you add time field (logins)

uses: pattern recognition, forecasting (trends, seasonality).

# timescaleDB features

fast ingestion of time series data (historic data)

time- oriented analytics functions (histogram)

continous aggregates 

data retention policies (data droping over period of time)

compression and jobs

availability of postgreSQL tools and ecosystem

# Create a hypertable

Hypertables are the core of Timescale. Hypertables enable Timescale to work efficiently with time-series data. Because Timescale is PostgreSQL, all the standard PostgreSQL tables, indexes, stored procedures and other objects can be created alongside your Timescale hypertables. This makes creating and working with Timescale tables similar to standard PostgreSQL.

## implementation
# small example

CREATE TABLE sensor_data (
    time TIMESTAMP WITHOUT TIME ZONE,
    sensor_id INT,
    value DOUBLE PRECISION
);

## -- Convert the table to a hypertable
This command designates the time column as the time dimension and converts the sensor_data table into a hypertable.

SELECT create_hypertable('sensor_data', 'time');

## -- Insert data into the hypertable
TimescaleDB will automatically handle the partitioning of this data into chunks based on the time dimension.

INSERT INTO sensor_data (time, sensor_id, value)
VALUES
   ('2023-01-01 12:00:00', 1, 23.5),
   ('2023-01-01 12:15:00', 2, 18.9),
   ('2023-01-01 12:30:00', 1, 21.2);

## -- Query for data within a specific time range

SELECT * FROM sensor_data
WHERE time >= '2023-01-01 12:00:00' AND time < '2023-01-01 12:30:00';

# example two:
using transport example 1 from https://docs.timescale.com/tutorials/latest/nyc-taxi-cab/dataset-nyc/

this example includes 3 steps:
1.set up
2.query data
3.bonus: set up compression


CREATE TABLE "rides"(
    vendor_id TEXT,
    pickup_datetime TIMESTAMP WITHOUT TIME ZONE NOT NULL,
    dropoff_datetime TIMESTAMP WITHOUT TIME ZONE NOT NULL,
    passenger_count NUMERIC,
    trip_distance NUMERIC,
    pickup_longitude  NUMERIC,
    pickup_latitude   NUMERIC,
    rate_code         INTEGER,
    dropoff_longitude NUMERIC,
    dropoff_latitude  NUMERIC,
    payment_type INTEGER,
    fare_amount NUMERIC,
    extra NUMERIC,
    mta_tax NUMERIC,
    tip_amount NUMERIC,
    tolls_amount NUMERIC,
    improvement_surcharge NUMERIC,
    total_amount NUMERIC
);

to convert it to hypertable:

SELECT create_hypertable('rides', 'pickup_datetime', 'payment_type', 2, create_default_indexes=>FALSE);

Create an index to support efficient queries by vendor, rate code, and passenger count:

CREATE INDEX ON rides (vendor_id, pickup_datetime DESC);
CREATE INDEX ON rides (rate_code, pickup_datetime DESC);
CREATE INDEX ON rides (passenger_count, pickup_datetime DESC);

# Create standard PostgreSQL tables for relational data

CREATE TABLE IF NOT EXISTS "payment_types"(
    payment_type INTEGER,
    description TEXT
);
INSERT INTO payment_types(payment_type, description) VALUES
(1, 'credit card'),
(2, 'cash'),
(3, 'no charge'),
(4, 'dispute'),
(5, 'unknown'),
(6, 'voided trip');

CREATE TABLE IF NOT EXISTS "rates"(
    rate_code   INTEGER,
    description TEXT
);
INSERT INTO rates(rate_code, description) VALUES
(1, 'standard rate'),
(2, 'JFK'),
(3, 'Newark'),
(4, 'Nassau or Westchester'),
(5, 'negotiated fare'),
(6, 'group ride');

# copy the data 
\COPY rides FROM nyc_data_rides.csv CSV;





