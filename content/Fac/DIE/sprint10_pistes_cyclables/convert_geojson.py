## convertir en GeoJson
import csv, json
from geojson import Feature, FeatureCollection, Point

features = []
with open("data-pm-sasdie-bus.csv", newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=';')
    for long1, lat1, long2, lat2, start_date, stop_date, pm, *rest in reader:
        latitude = (float(lat1)+float(lat2))/2
        longitude = (float(long1)+float(long2))/2
        latitude, longitude = map(float, (latitude, longitude))
        features.append(
            Feature(
                geometry = Point((longitude, latitude)),
                properties = {
                    'start_date': start_date,
                    'stop_date' : stop_date,
                    'pm' : pm
                }
            )
        )

collection = FeatureCollection(features)
with open("data_bus.json", "w") as f:
    f.write('%s' % collection)
