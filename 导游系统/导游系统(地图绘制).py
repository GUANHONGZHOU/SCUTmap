from pyecharts.charts import Graph
from pyecharts import options as opts

# 定义图的节点和边
nodes = [
    {"name": "博学楼", "x": 100, "y": 200},
    {"name": "北湖", "x": 200, "y": 100},
    {"name": "旧校训石", "x": 300, "y": 200},
    {"name": "逸夫人文馆", "x": 400, "y": 100},
    {"name": "西湖", "x": 500, "y": 200},
    {"name": "校友之家", "x": 600, "y": 100},
    {"name": "医院", "x": 700, "y": 200},
    {"name": "孙中山先生像", "x": 800, "y": 100},
    {"name": "道明游泳馆", "x": 900, "y": 200},
    {"name": "图书馆", "x": 1000, "y": 100},
]

# 定义边及权重（距离）
edges = [
    {"source": "博学楼", "target": "北湖", "value": 1},
    {"source": "博学楼", "target": "旧校训石", "value": 4},
    {"source": "北湖", "target": "旧校训石", "value": 2},
    {"source": "北湖", "target": "逸夫人文馆", "value": 10},
    {"source": "旧校训石", "target": "逸夫人文馆", "value": 8},
    {"source": "旧校训石", "target": "西湖", "value": 9},
    {"source": "逸夫人文馆", "target": "医院", "value": 6},
    {"source": "逸夫人文馆", "target": "校友之家", "value": 3},
    {"source": "西湖", "target": "校友之家", "value": 9},
    {"source": "西湖", "target": "孙中山先生像", "value": 4},
    {"source": "西湖", "target": "道明游泳馆", "value": 11},
    {"source": "西湖", "target": "图书馆", "value": 6},
    {"source": "校友之家", "target": "医院", "value": 4},
    {"source": "校友之家", "target": "孙中山先生像", "value": 7},
    {"source": "医院", "target": "孙中山先生像", "value": 4},
    {"source": "孙中山先生像", "target": "图书馆", "value": 5},
    {"source": "道明游泳馆", "target": "图书馆", "value": 6},
]

# 创建Graph对象
graph = Graph()

# 添加节点和边
graph.add(
    "校园景点",
    nodes,
    edges,
    repulsion=8000,  # 节点之间的斥力
    is_rotate_label=True,  # 是否旋转标签
    label_opts=opts.LabelOpts(position="right"),  # 标签位置
)

# 设置全局配置项
graph.set_global_opts(
    title_opts=opts.TitleOpts(title="校园景点导游图"),
    legend_opts=opts.LegendOpts(is_show=False),  # 不显示图例
)

# 渲染图表
graph.render("校园导游图.html")
