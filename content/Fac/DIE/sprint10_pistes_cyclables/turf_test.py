from geojson import Feature
from ipyleaflet import Map, GeoJSON, LayersControl
from turfpy.transformation import intersect
import json

from ipyleaflet import Map, GeoJSON
from geojson import LineString, Feature
from turfpy.misc import line_intersect

file = open('amenagement_cyclable.geojson')
data=json.load(file)
coord=[]
for i in range(len(data['features'])):
    coord.append(data['features'][i]['geometry']['coordinates'])


f = Feature(geometry=LineString(coord))

b = Feature(geometry=LineString([[[-1.655531070374233, 48.18287737794509], [-1.655547275334727, 48.18281240346689], [-1.655562449867638, 48.182770011182264], [-1.655567941523111, 48.18272986024314], [-1.655567772123278, 48.182700475011956], [-1.655570205729542, 48.18268152135188], [-1.655557936462581, 48.18267507938514]]]))


geo_json_1 = GeoJSON(name="Pistes cyclabes", data=f)

geo_json_2 = GeoJSON(name='intersection', data=b, style={'color': 'green'})

#geojson = GeoJSON(name='Intersection', data=line_intersect(f,b), style={'color': 'red'})


m = Map(center=[48.1113, -1.6809], zoom_start=13)

m.add_layer(geo_json_1)
m.add_layer(geo_json_2)
#m.add_layer(geojson)

control = LayersControl(position='topright')
m.add_control(control)

m.save("carte2.html")
