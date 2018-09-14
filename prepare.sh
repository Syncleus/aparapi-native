#!/bin/sh
mkdir include
(cd java && mvn clean package -DskipTests=true -Dmaven.javadoc.skip=true)
