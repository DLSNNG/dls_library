
<?php

  module_load_include('inc', 'dls_resource', 'rest_routes');

  class DlsLibraryResources {
    
    public static function TestResource() {
      $resource = new RestRoutesResource('dls_library', 'TestRoute');
      return $resource;
    }
    
  }

