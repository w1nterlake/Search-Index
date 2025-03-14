#include "ConverterJSON.h"


int main(){
    ConverterJSON converter;
    InvertedIndex i;
    i.UpdateDocumentBase(converter.GetDocumets());
    SearchServer server(i);
    converter.putAnswers(server.search(converter.GetRequests()));

    return 0;
}