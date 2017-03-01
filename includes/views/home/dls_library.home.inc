
<?php

  module_load_include('inc', 'dls_library', 'theme/dls_library.home_page');
  
  // @return render array
  function view_dls_library_home() {
    // grab and format data
    $props = get_props();
    // render view
    $block = theme('home_page', array(
      'objects' => $props['objects'],
      'target' => $props['target'],
      'field1' => $props['field1'],
      'field2' => $props['field2'],
    ));
    // add styles to page
    $block['#attached']['css'][] = drupal_get_path('module', 'dls_library')
          . '/includes/views/home/dls_library.home.css';
          
    return $block;
  }

  // @return array of properties to be used by theme function
  function get_props() {
    $object1 = (object) array('name' => 'alvin', 'age' => '3');
    $object2 = (object) array('name' => 'simon', 'age' => '4');
    $object3 = (object) array('name' => 'theodore', 'age' => '5');
    
    $objects = array($object1, $object2, $object3);
    
    $props = array(
      'objects' => $objects,
      'target' => current_path(),
      'field1' => 'blah',
      'field2' => 'blahhh',
    );
    return $props;
  }