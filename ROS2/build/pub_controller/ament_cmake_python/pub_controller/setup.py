from setuptools import find_packages
from setuptools import setup

setup(
    name='pub_controller',
    version='0.0.0',
    packages=find_packages(
        include=('pub_controller', 'pub_controller.*')),
)
