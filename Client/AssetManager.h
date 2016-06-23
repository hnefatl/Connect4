#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include <map>

enum UnloadBehaviour;

template<typename T>
class AssetManager
{
protected:
	std::map<std::string, T *> Cache; // Maps a resource name to the actual asset
	std::map<T *, std::string> Reverse; // Maps the asset back to the resource name, used for unloading assets
	std::map<T *, unsigned int> Usage; // Maps an asset to the number of active users

	UnloadBehaviour Behaviour;

	virtual T *LoadAsset(const std::string &Path) = 0;
	virtual void DestroyAsset(T *Asset) = 0;

public:
	AssetManager(const UnloadBehaviour Behaviour);
	~AssetManager();

	T *Load(const std::string &Path);
	void Unload(T *Asset);

	bool Loaded(const std::string &Path) const;

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