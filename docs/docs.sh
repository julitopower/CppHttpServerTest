#!/bin/env bash
for f in $(ls *.uml)
do
    cat $f | docker run --rm -v $(pwd):/opt/src -i think/plantuml > $f.svg
    rsvg-convert $f.svg -o $f.png
done
