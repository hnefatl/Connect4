#ifndef _ASSETMANAGER_IMPL_H
#define _ASSETMANAGER_IMPL_H

#include "AssetManager.h"

enum UnloadBehaviour
{
	Immediate,
	OnEmpty,
};

template<typename T>
AssetManager<T>::AssetManager(const UnloadBehaviour Behaviour)
	:Behaviour(Behaviour)
{
}
template<typename T>
AssetManager<T>::~AssetManager()
{
	UnloadAll();
}

template<typename T>
bool AssetManager<T>::Loaded(const std::string &Name) const
{
	return Cache.find(Name) != Cache.end();
}

template<typename T>
T *AssetManager<T>::Load(const std::string &Path)
{
	// Check if it's already in the cache
	std::map<std::string, T *>::iterator Loc = Cache.find(Name);
	if (Loc != Cache.end()) // It is
	{
		Usage[Loc->second]++; // One more reference being handed out
		return Loc->second;
	}

	T *Asset = LoadAsset(Path);

	Cache.emplace(Name, Asset); // Store in cache
	Reverse.emplace(Asset, Name);
	Usage.emplace(Asset, 1); // Record our one reference so far
	return Texture;
}

template<typename T>
void AssetManager<T>::Unload(T *Asset)
{
	std::map<T *, unsigned int>::iterator Use = Usage.find(Asset);
	if (Use == Usage.end()) // Not stored in the usage list
		return;

	Use->second--; // Unload one use

	if (Use->second == 0 && Behaviour == UnloadBehaviour::Immediate) // If no more references to it and we're set to unload immediately
	{
		std::map<T *, std::string>::iterator Name = Reverse.find(Asset); // Get the name
		if (Name == Reverse.end()) // Unloading a texture that's no longer loaded
			return;

		Cache.erase(Name->second);
		Usage.erase(Asset);
		Reverse.erase(Asset);
		DestroyAsset(Asset);
	}
}

template<typename T>
void AssetManager<T>::UnloadUnused()
{
	for (std::map<std::string, T *>::iterator i = Cache.begin(); i != Cache.end(); i++)
	{
		if (Usage[i->second] == 0) // No references
		{
			T *Ref = i->second;
			Usage.erase(Ref);
			Reverse.erase(Ref);
			Cache.erase(i->first);
			DestroyAsset(Ref);
			if (i != Cache.begin())
				i--;
		}
	}
}
template<typename T>
void AssetManager<T>::UnloadAll()
{
	Reverse.clear();
	Usage.clear();
	for (std::map<std::string, T *>::iterator i = Cache.begin(); i != Cache.end(); i++)
		DestroyAsset(i->second);
	Cache.clear();
}


template<typename T>
UnloadBehaviour AssetManager<T>::GetUnloadBehaviour() const
{
	return Behaviour;
}
template<typename T>
void AssetManager<T>::SetUnloadBehaviour(const UnloadBehaviour Behaviour)
{
	this->Behaviour = Behaviour;
}

#endif