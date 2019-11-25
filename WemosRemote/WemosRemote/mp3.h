void initMP3()
{
  out = new AudioOutputI2SNoDAC();
  mp3 = new AudioGeneratorMP3();
}


void stopMP3()
{
  mp3->stop();
}

void playMP3(const char* path)
{
  file = new AudioFileSourceSPIFFS(path);
  id3 = new AudioFileSourceID3(file);
  mp3->begin(id3, out);
}



void mp3PlayTrack(const char* track)
{
 // message ("Play: " + String (track));
  if (mp3->isRunning()) { mp3->stop();}
  if (!mp3->isRunning())
  {
    file = new AudioFileSourceSPIFFS(track);
    id3 = new AudioFileSourceID3(file);
  // delay(200);
     mp3->begin(id3, out); 
  }
}
