#include "SoundHandler.h"
#include <iostream>


// variable declarations
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play


static Uint32 wav_length; // length of our sample
static Uint8 *wav_buffer; // buffer containing our audio file
static SDL_AudioSpec wav_spec; // the specs of our piece of music

static bool stop;
// audio callback function
// here you have to copy the data of your audio buffer into the
// requesting audio buffer (stream)
// you should only copy as much as the requested length (len)
void my_audio_callback(void *userdata, Uint8 *stream, int len) {

	if (audio_len == 0)
	{
		audio_pos = wav_buffer; // copy sound buffer
		audio_len = wav_length; // copy file length
	}
	if (stop)
	{
		return;
	}

	len = (len > audio_len ? audio_len : len);
	SDL_memcpy (stream, audio_pos, len); 					// simply copy from one buffer into the other
	//SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another

	audio_pos += len;
	audio_len -= len;
}

void SoundHandler::Init()
{
	

}
void SoundHandler::Play(int music)
{
	stop = false;
	/* Load the WAV */
	// the specs, length and buffer of our wav are filled
	
	if (music == 0)
		SDL_LoadWAV("Data/Audio/SNP1.wav", &wav_spec, &wav_buffer, &wav_length);
	
	if (music == 1)
		SDL_LoadWAV("Data/Audio/SNP2.wav", &wav_spec, &wav_buffer, &wav_length);
	
	
	// set the callback function
	wav_spec.callback = my_audio_callback;
	wav_spec.userdata = NULL;
	// set our global static variables
	audio_pos = wav_buffer; // copy sound buffer
	audio_len = wav_length; // copy file length

	/* Open the audio device */
	if (SDL_OpenAudio(&wav_spec, NULL) < 0){
		fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
		exit(-1);
	}

	/* Start playing */
	SDL_PauseAudio(0);

}

void SoundHandler::Stop()
{
	SDL_PauseAudio(1);
	stop = true;
	SDL_FreeWAV(wav_buffer);
	SDL_CloseAudio();
}

