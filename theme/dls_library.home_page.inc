
<?php

  module_load_include('inc', 'dls_library', 'theme/dls_library.object_link_list');
  module_load_include('inc', 'dls_library', 'theme/dls_library.custom_button');
  module_load_include('inc', 'dls_library', 'theme/dls_library.object_link_table');
  module_load_include('inc', 'dls_library', 'forms/dls_library.test_form');

  /*************************************************************
   *
   *  @param: objects = array
   *  @param: target = string
   *  @param: field1 = string
   *  @param: field2 = string
   *  @returns: drupal render array
   *
   *************************************************************/

  function theme_home_page($variables) {
  

    // Validate and set objects property
    if((gettype($variables['objects']) == 'array')) { 
      $objects = $variables['objects'];
    }
    else {
      form_set_error('', 'theme home_page - objects should be array. Received ' . gettype($variables['objects']) . '.');
      return;
    }
    // Validate and set target property
    if((gettype($variables['target']) == 'string')) { 
      $target = $variables['target'];
    }
    else {
      form_set_error('', 'theme home_page - target should be string. Received ' . gettype($variables['target']) . '.');
      return;
    }
    // Validate and set field1 property
    if((gettype($variables['field1']) == 'string')) { 
      $field1 = $variables['field1'];
    }
    else {
      form_set_error('', 'theme home_page - field1 should be string. Received ' . gettype($variables['field1']) . '.');
      return;
    }
    // Validate and set field2 property
    if((gettype($variables['field2']) == 'string')) { 
      $field2 = $variables['field2'];
    }
    else {
      form_set_error('', 'theme home_page - target should be string. Received ' . gettype($variables['field2']) . '.');
      return;
    }

    ///////////////////////////////////////
    //  Render Component
    ///////////////////////////////////////
    
    $block = array(
      '#type' => 'markup',
      'list' => theme('object_link_list', array(
        'objects' => $objects,
        'displayProp' => 'name',
        'queryParamMap' => array(
          'name' => 'name',
          'theirAge' => 'age',
        ),
      )),
      'table' => theme('object_link_table', array(
        'objects' => $objects,
        'mapping' => array(
          'Name' => array(
            'display' => 'name',
            'url' => current_path(),
            'keepParams' => TRUE,
          ),
          'Years old' => array(
            'display' => 'age', 
          ),
        ),
        'class' => 'test-table',
      )),
      'form' => drupal_get_form('test_form', array(
        'field1' => $field1,
        'field2' => $field2,
        'target' => $target,  
      )),
      'button' => theme('custom_button', array(
        'display' => 'Click Me!',
        'class' => 'red',
      )),
    );
    
    return $block;
  }

  