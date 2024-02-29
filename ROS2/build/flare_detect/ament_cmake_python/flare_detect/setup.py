from setuptools import find_packages
from setuptools import setup

setup(
    name='flare_detect',
    version='0.0.0',
    packages=find_packages(
        include=('flare_detect', 'flare_detect.*')),
)
