for f in $(ls *.uml)
do
    cat $f | docker run --rm -v $(pwd):/opt/src -i think/plantuml -tpng > $f.png
done
