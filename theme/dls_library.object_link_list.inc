
<?php

  module_load_include('inc', 'dls_library', 'theme/dls_library.link_list_item');

  /*************************************************************
   *
   *  @param: objects = array
   *  @param: displayProp = string
   *  @param: baseURL = string
   *  @param: queryParamMap = array (this is an queryParamName => objectProperty mapping)
   *  @param: class = string
   *  @returns: drupal render array
   *
   *************************************************************/

  function theme_object_link_list($variables) {

    // Validate and set objects property
    if((gettype($variables['objects']) == 'array')) { 
      $objects = $variables['objects'];
    }
    else {
      form_set_error('', 'theme object_link_list - objects should be array. Received ' . gettype($variables['objects']) . '.');
      return;
    }
    // Validate and set displayProp property
    if((gettype($variables['displayProp']) == 'string')) { 
      $displayProp = $variables['displayProp'];
    }
    else {
      form_set_error('', 'theme object_link_list - itemProps should be array. Received ' . gettype($variables['itemProps']) . '.');
      return;
    }
    // Validate and set baseURL property
    if((gettype($variables['baseURL']) == 'string')) { 
      $baseURL = $variables['baseURL'];
    }
    else {
      $baseURL = current_path();
    }
    // Validate and set queryParamMap property
    if((gettype($variables['queryParamMap']) == 'array')) { 
      $queryParamMap = $variables['queryParamMap'];
    }
    else {
      form_set_error('', 'theme object_link_list - queryParamMap should be array. Received ' . gettype($variables['queryParamMap']) . '.');
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
      // determine url to use
      $queryParams = array();
      foreach($queryParamMap as $name => $prop) {
        $queryParams[$name] = $object->$prop;
      }
      $url = url($baseURL, array('query' => $queryParams));
      // determine text to display
      $display = $object->$displayProp;
      // add link_list_item li to ul
      $block[] = theme('link_list_item', array(
        'display' => $display,
        'url' => $url,
      ));
    }
    
    return $block;
  }

