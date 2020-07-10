void AnnotationsManager::SetAnnotationState(QString ann, bool state){
    activeAnnotations[ann] = state;
}

QString AnnotationsManager::CheckAnnotation (QString ann){
    QString aux = ann;
    if(!activeAnnotations.value(ann,false)
            && (ann == "N"
                || ann == "S"
                || ann == "V"
                || ann == "F"
                || ann == "Q")
            ){
        aux = "N";
    }
    return aux;
}