﻿#include <ResourceLoader.hpp>
#include "EffekseerGodot.CurveLoader.h"
#include "../RendererGodot/EffekseerGodot.Utils.h"
#include "../EffekseerResource.h"

namespace EffekseerGodot
{

Effekseer::CurveRef CurveLoader::Load(const char16_t* path)
{
	// Load by Godot
	auto loader = godot::ResourceLoader::get_singleton();
	auto resource = loader->load(Convert::String16(path), "");
	if (!resource.is_valid())
	{
		return nullptr;
	}

	auto efkres = godot::as<godot::EffekseerResource>(resource.ptr());
	auto& data = efkres->get_data_ref();

	return Load(data.read().ptr(), data.size());
}

Effekseer::CurveRef CurveLoader::Load(const void* data, int32_t size)
{
	return Effekseer::MakeRefPtr<Effekseer::Curve>(data, size);
}

void CurveLoader::Unload(Effekseer::CurveRef data)
{
}

} // namespace EffekseerGodot

