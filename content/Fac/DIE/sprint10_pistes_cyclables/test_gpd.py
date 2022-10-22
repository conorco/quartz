import geopandas as gpd
import numpy as np
import shapely.geometry
import folium

rest_VIC = gpd.read_file(
    "https://raw.githubusercontent.com/codeforgermany/click_that_hood/main/public/data/melbourne.geojson"
)

# select a point randomly from total bounds of geometry
buffer_df = gpd.GeoDataFrame(
    geometry=[
        shapely.geometry.Point(
            np.random.uniform(*rest_VIC.total_bounds[[0, 2]], size=1)[0],
            np.random.uniform(*rest_VIC.total_bounds[[1, 3]], size=1)[0],
        )
    ],
    crs=rest_VIC.crs,
)

buffer_df = gpd.GeoDataFrame(
    geometry=buffer_df.to_crs(buffer_df.estimate_utm_crs())
    .buffer(8 * 10**3)
    .to_crs(buffer_df.crs)
)


# need overlay not sjoin
intersection_MeshBlock = gpd.overlay(buffer_df, rest_VIC, how="intersection")

m = rest_VIC.explore(name="base", style_kwds={"fill":False}, width=400, height=300)
m = buffer_df.explore(m=m, name="buffer", style_kwds={"fill":False})
m = intersection_MeshBlock.explore(m=m, name="intersection", style_kwds={"fillColor":"orange"})
folium.LayerControl().add_to(m)

import geopandas as gpd
import matplotlib.pyplot as plt
