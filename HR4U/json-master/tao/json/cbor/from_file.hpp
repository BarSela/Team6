// Copyright (c) 2018-2020 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAO_JSON_CBOR_FROM_FILE_HPP
#define TAO_JSON_CBOR_FROM_FILE_HPP

#include <filesystem>
#include <utility>

#include "../events/to_value.hpp"
#include "../events/transformer.hpp"

#include "events/from_file.hpp"

namespace tao::json::cbor
{
   template< template< typename... > class Traits, template< typename... > class... Transformers >
   [[nodiscard]] basic_value< Traits > basic_from_file( const std::filesystem::path& path )
   {
      json::events::transformer< json::events::to_basic_value< Traits >, Transformers... > consumer;
      events::from_file( consumer, path );
      return std::move( consumer.value );
   }

   template< template< typename... > class... Transformers >
   [[nodiscard]] value from_file( const std::filesystem::path& path )
   {
      return basic_from_file< traits, Transformers... >( path );
   }

}  // namespace tao::json::cbor

#endif
