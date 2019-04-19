#include "StreamTable.h"



StreamTable::StreamTable(Storage* storage): storage(storage){
	streams = std::map<std::string, FileStream*>();
}


StreamTable::~StreamTable(){
	for (std::map<std::string, FileStream*>::iterator it = streams.begin(); it != streams.end(); it++) delete it->second;
}


FileStream* StreamTable::get_stream(std::string name){
	std::map<std::string, FileStream*>::iterator stream = streams.find(name);
	if (stream == streams.end()) return nullptr;
	return stream->second;
}

FileStream* StreamTable::create_stream(std::string name){
	FileStream* stream = new FileStream(storage);
	streams.insert(std::pair<std::string, FileStream*>(name, stream));
	return stream;
}

void StreamTable::delete_stream(std::string name){
	streams.erase(name);
}
