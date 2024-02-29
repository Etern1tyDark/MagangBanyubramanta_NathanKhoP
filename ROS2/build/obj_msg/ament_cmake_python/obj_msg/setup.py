from setuptools import find_packages
from setuptools import setup

setup(
    name='obj_msg',
    version='0.0.0',
    packages=find_packages(
        include=('obj_msg', 'obj_msg.*')),
)
