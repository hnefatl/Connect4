#ifndef _ASSETMANAGER_IMPL_H
#define _ASSETMANAGER_IMPL_H

#include "AssetManager.h"

enum UnloadBehaviour
{
	Immediate,
	OnEmpty,
};

template<typename AssetType, typename KeyType>
AssetManager<AssetType, KeyType>::AssetManager(const UnloadBehaviour Behaviour)
	:Behaviour(Behaviour)
{
}
template<typename AssetType, typename KeyType>
AssetManager<AssetType, KeyType>::~AssetManager()
{
	UnloadAll();
}


template<typename AssetType, typename KeyType>
AssetType *AssetManager<AssetType, KeyType>::Load(const AssetSettings &Settings)
{
	KeyType Key = GetKey(Settings);

	std::map<KeyType, AssetType *>::iterator Loc = Cache.find(Key);
	if (Loc != Cache.end()) // If contained
	{
		Usage[Loc->second]++; // One more reference being handed out
		return Loc->second;
	}

	AssetType *Asset = LoadAsset(Settings);

	if (Asset == nullptr)
		return nullptr;

	Cache.emplace(Key, Asset); // Store in cache
	Reverse.emplace(Asset, Key);
	Usage.emplace(Asset, 1); // Record our one reference so far
	return Asset;
}

template<typename AssetType, typename KeyType>
void AssetManager<AssetType, KeyType>::Unload(AssetType *Asset)
{
	std::map<AssetType *, unsigned int>::iterator Use = Usage.find(Asset);
	if (Use == Usage.end()) // Not stored in the usage list
		return;

	Use->second--; // Unload one use

	if (Use->second == 0 && Behaviour == UnloadBehaviour::Immediate) // If no more references to it and we're set to unload immediately
	{
		std::map<AssetType *, KeyType>::iterator Name = Reverse.find(Asset); // Get the name
		if (Name == Reverse.end()) // Unloading a texture that's no longer loaded
			return;

		Cache.erase(Name->second);
		Usage.erase(Asset);
		Reverse.erase(Asset);
		DestroyAsset(Asset);
	}
}

template<typename AssetType, typename KeyType>
bool AssetManager<AssetType, KeyType>::IsLoaded(const KeyType &Key) const
{
	return Cache.find(Key) != Cache.end();
}

template<typename AssetType, typename KeyType>
void AssetManager<AssetType, KeyType>::UnloadUnused()
{
	for (std::map<KeyType, AssetType *>::iterator i = Cache.begin(); i != Cache.end(); i++)
	{
		if (Usage[i->second] == 0) // No references
		{
			AssetType *Ref = i->second;
			Usage.erase(Ref);
			Reverse.erase(Ref);
			Cache.erase(i->first);
			DestroyAsset(Ref);
			if (i != Cache.begin())
				i--;
		}
	}
}
template<typename AssetType, typename KeyType>
void AssetManager<AssetType, KeyType>::UnloadAll()
{
	Reverse.clear();
	Usage.clear();
	for (std::map<KeyType, AssetType *>::iterator i = Cache.begin(); i != Cache.end(); i++)
		DestroyAsset(i->second);
	Cache.clear();
}


template<typename AssetType, typename KeyType>
UnloadBehaviour AssetManager<AssetType, KeyType>::GetUnloadBehaviour() const
{
	return Behaviour;
}
template<typename AssetType, typename KeyType>
void AssetManager<AssetType, KeyType>::SetUnloadBehaviour(const UnloadBehaviour Behaviour)
{
	this->Behaviour = Behaviour;
}

#endif