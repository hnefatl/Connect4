#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include <map>
#include <string>

enum UnloadBehaviour;

template<typename AssetType, typename KeyType, typename SettingsType>
class AssetManager
{
protected:
	std::map<KeyType, AssetType *> Cache; // Maps a resource name to the actual asset
	std::map<AssetType *, KeyType> Reverse; // Maps the asset back to the resource name, used for unloading assets
	std::map<AssetType *, unsigned int> Usage; // Maps an asset to the number of active users

	UnloadBehaviour Behaviour;
	std::string AssetDir;

	virtual KeyType GetKey(const SettingsType &Settings) const = 0;
	virtual AssetType *LoadAsset(const SettingsType &Settings) = 0;
	virtual void DestroyAsset(AssetType *Asset) = 0;

public:
	AssetManager(const std::string &AssetDir, const UnloadBehaviour Behaviour);
	~AssetManager();

	AssetType *Load(const SettingsType &Settings);
	void Unload(AssetType *Asset);

	bool IsLoaded(const KeyType &Key) const;

	virtual void UnloadUnused();
	virtual void UnloadAll();

	UnloadBehaviour GetUnloadBehaviour() const;
	void SetUnloadBehaviour(const UnloadBehaviour Behaviour);
};


// Include the implementation file.
// Provides .cpp style implementation stuff but needs to be included in the header
// as we're using templates so definition technically has to be in the same file as declaration
#include "AssetManager_impl.h"

#endif