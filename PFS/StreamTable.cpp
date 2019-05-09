#include "StreamTable.h"



StreamTable::StreamTable(Storage* storage): storage(storage){
	streams = std::map<std::string, FileStream>();
}


StreamTable::~StreamTable(){
	//for (std::map<std::string, FileStream*>::iterator it = streams.begin(); it != streams.end(); it++) delete it->second;
}


std::vector<std::string> StreamTable::get_streams(){
	std::vector<std::string> res;
	for (const auto stream : streams) res.push_back(stream.first);
	return res;
}

FileStream* StreamTable::get_stream(std::string name){
	std::map<std::string, FileStream>::iterator stream = streams.find(name);
	if (stream == streams.end()) return nullptr;
	return &stream->second;
}

FileStream* StreamTable::create_stream(std::string name){
	//FileStream* stream = new ;
	streams.insert(std::pair<std::string, FileStream>(name, FileStream(storage)));
	return get_stream(name);
}

void StreamTable::delete_stream(std::string name, bool full){
	if (full) {
		auto stream = streams.find(name);
		stream->second.erase();
		//delete stream->second;
	}
	streams.erase(name);
}
