TEMPLATE = subdirs

SUBDIRS += app \

CONFIG(debug, debug|release){
    SUBDIRS += tst_component1 \
        tst_component2 \
        tst_component3 
        ...
}
