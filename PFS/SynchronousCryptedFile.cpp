#include "SynchronousCryptedFile.h"



SynchronousCryptedFile::SynchronousCryptedFile(Storage* storage, Path path): File::File(storage, path)
{
}


SynchronousCryptedFile::~SynchronousCryptedFile()
{
}

void SynchronousCryptedFile::crypt(std::string password){
	FileByteStream* stream  = (FileByteStream*)this->open(0);

	for (int i = 0; i < stream->get_size(); ++i) {
		stream->write(i, stream->read(i) ^ password[i % password.length()]);
	}

	delete stream;
}
