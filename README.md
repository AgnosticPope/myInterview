Compile instructions:
qmake && make

Usage:
./riverView corn_ear.csv

Design Notes:
I decided to use both C++11 (since auto makes typing easier in templating easier) and Qt (for performance: copy contructor of QVector is O(1) -- only on modification does it deep copy).  As you can see in the git history, I started with the u_int_8 type and then expanded it to be a template class.  After I got off the phone, I decided to try the "extra credit" by using a generic matrix class.
