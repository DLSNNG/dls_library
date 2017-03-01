
<?php

  module_load_include('inc', 'dls_library', 'theme/dls_library.list_item');

  /*************************************************************
   *
   *  @param: objects = array of objects
   *  @param: displayProp = string
   *  @param: class = string
   *  @returns: drupal render array
   *
   *************************************************************/

  function theme_object_list($variables) {
  

    // Validate and set objects property
    if((gettype($variables['objects']) == 'array')) { 
      $objects = $variables['objects'];
    }
    else {
      form_set_error('', 'theme object_list - objects should be array. Received ' . gettype($variables['objects']) . '.');
      return;
    }
    // Validate and set displayProp property
    if((gettype($variables['displayProp']) == 'string')) { 
      $displayProp = $variables['displayProp'];
    }
    else {
      form_set_error('', 'theme object_list - displayProp should be string. Received ' . gettype($variables['displayProp']) . '.');
      return;
    }
    
    // Validate and set class property
    if((gettype($variables['class']) == 'string')) { 
      $class = $variables['class'];
    }
    else {
      form_set_error('', 'theme object_list - class should be string. Received ' . gettype($variables['class']) . '.');
      return;
    }

    ///////////////////////////////////////
    //  Render Component
    ///////////////////////////////////////
    
    $block = array(
      '#type' => 'markup',
      '#prefix' => '<ul class="' . $class . '">',
      '#suffix' => '</ul>',
    );
    
    foreach($objects as $object) {
      // determine text to display
      $display = $object->$displayProp;
      // add li to ul
      $block[] = theme('list_item', array(
        'display' => $display,
      ));
    }
    
    return $block;
  }

