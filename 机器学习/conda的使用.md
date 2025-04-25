# `conda`的使用

## 1.conda搭建虚拟环境

如果在C盘即默认盘创建虚拟环境

```bash
conda create -n garbage-env python=3.8
conda activate garbage-env
```

在D盘建立虚拟环境

```bash
conda create --prefix D:\conda_envs\garbage-env python=3.8
conda activate D:\conda_envs\myenv
```

## 2.安装依赖包，清华源

```bash
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge/
conda config --set show_channel_urls yes
```

```bash
pip install tensorflow==2.10.0 -i https://pypi.tuna.tsinghua.edu.cn/simple
pip install numpy>=1.19.5 -i https://pypi.tuna.tsinghua.edu.cn/simple
pip install matplotlib>=3.2.2 -i https://pypi.tuna.tsinghua.edu.cn/simple
pip install scikit-learn>=0.24.2 -i https://pypi.tuna.tsinghua.edu.cn/simple

```

