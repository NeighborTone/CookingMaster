#include "BaseInfo.h"
#include "NoteMng.h"

NoteMng::NoteMng() :
		timeCnt(0),
		size(note.size())
{};

NoteMng::~NoteMng() {}

void NoteMng::Init() {
	timeCnt = 0;
}

void NoteMng::AddNote(float hitFlame, Vege v, Direction d) {
	Note newNote;
	newNote.Init(hitFlame, v, d);
	note.push_back(newNote);
	size = note.size();
}

void NoteMng::Update() {
	timeCnt++;
	NoteAppear();
	for (unsigned int i = 0; i < size; ++i) {
		note[i].Update();
	}
}

void NoteMng::NoteAppear() {
	for (unsigned int i = 0; i < size; ++i) {
		if (timeCnt == note[i].GetAppearFlame(note[i])) {
			note[i].Appear();
		}
	}
}

void NoteMng::Render() {
	for (unsigned int i = 0; i < size; ++i) {
		note[i].Render();
	}

}