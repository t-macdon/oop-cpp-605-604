# Take in the project folder as arg 1

PROJECT=$1

if [ -z $PROJECT ]; then
    echo "Usage " $0 " <Project Folder>"
    exit 1;
fi

cd $PROJECT;
mkdir -p ./pdf
rm -rf ./pdf/*

for f in `find . -type f -name "*.cpp" -o -name "*.h"`; do
    # Create postscript files of all of the source files
    nvim -e -c "hardcopy > %.ps" -c q $f

    # Convert all postscript files to pdf
    ps2pdf ${f}.ps ${f}.pdf
done

# Move all pdf files to pdf folder
mv `find . -type f -name *.pdf` ./pdf

# Delete all leftover ps files
rm `find . -type f -name *.ps`