# Modules
- [Haversine](https://pypi.org/project/haversine/) : Calculate the distance (in various units) between two points on Earth using their latitude and longitude.
- [Geos](https://geos.readthedocs.io/en/latest/users.html#usage)
- [Folium](https://python-visualization.github.io/folium/quickstart.html)
- [Plot lines with Folium](https://deparkes.co.uk/2016/06/03/plot-lines-in-folium/)

Pour inverser les lat/long :
```python
folium.utilities._locations_mirror(donnees)
```

Folium lit le format `GeoJSON` => utiliser ce format pour lire les coordonnées
