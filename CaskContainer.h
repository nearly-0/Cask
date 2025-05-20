//
// Created by skywh on 25. 5. 21.
//

#pragma once

#include <EASTL/vector.h>
#include <EASTL/string.h>
#include <EASTL/unordered_map.h>
#include <EASTL/unique_ptr.h>

namespace Cask
{
    template <typename T>
    using Vector = eastl::vector<T>;

    using String = eastl::string;

    template <typename K, typename V>
    using HashMap = eastl::unordered_map<K, V>;

    template <typename T>
    using UniquePtr = eastl::unique_ptr<T>;
}