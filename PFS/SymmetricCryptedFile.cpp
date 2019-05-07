#include "SymmetricCryptedFile.h"



SymmetricCryptedFile::SymmetricCryptedFile(Storage* storage, Path path): File::File(storage, path)
{
}

SymmetricCryptedFile::SymmetricCryptedFile(File file): File::File(file){
	for (std::string name : file.get_streams()) file.delete_stream(name, false);
}


SymmetricCryptedFile::~SymmetricCryptedFile()
{
}
void SymmetricCryptedFile::crypt(std::string password){
	FileByteStream* stream  = (FileByteStream*)this->open(0);

	for (int i = 0; i < stream->get_size(); ++i) {
		stream->write(i, stream->read(i) ^ password[i % password.length()]);
	}

	delete stream;
}
