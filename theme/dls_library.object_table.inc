
<?php

  /*************************************************************
   *
   *  @param: objects = array of objects
   *  @param: mapping = array of header => prop pairs
   *  @param: class = string
   *  @returns: drupal render array
   *
   *************************************************************/

  function theme_object_table($variables) {
  

    // Validate and set objects property
    if((gettype($variables['objects']) == 'array')) { 
      $objects = $variables['objects'];
    }
    else {
      form_set_error('', 'theme object_table - objects should be array. Received ' . gettype($variables['objects']) . '.');
      return;
    }
    // Validate and set mapping property
    if((gettype($variables['mapping']) == 'array')) { 
      $mapping = $variables['mapping'];
    }
    else {
      form_set_error('', 'theme object_table - mapping should be array. Received ' . gettype($variables['mapping']) . '.');
      return;
    }
    // Validate and set class property
    if((gettype($variables['class']) == 'string')) { 
      $class = $variables['class'];
    }
    else {
      form_set_error('', 'theme object_table - class should be string. Received ' . gettype($variables['class']) . '.');
      return;
    }

    ///////////////////////////////////////
    //  Render Component
    ///////////////////////////////////////
    
    // build thead
    $thead = build_thead($mapping);
    // build tbody
    $tbody = build_tbody($objects, $mapping);
    
    $block = array(
      '#type' => 'markup',
      'thead' => $thead,
      'tbody' => $tbody,
      '#prefix' => '<table class="' . $class . '">',
      '#suffix' => '</table>'
    );
    return $block;
  }

  function build_thead($mapping) {
    // build thead
    $thead = array(
      '#type' => 'markup',
      '#prefix' => '<thead><tr>',
      '#suffix' => '</tr></thead>'
    );
    // populate thead
    foreach($mapping as $header => $prop) {
      $thead[] = array(
        '#type' => 'markup',
        '#markup' => $header,
        '#prefix' => '<th>',
        '#suffix' => '</th>',
      );
    }
    return $thead;
  }
  
  function build_tbody($objects, $mapping) {
    // build tbody
    $tbody = array(
      '#type' => 'markup',
      '#prefix' => '<tbody>',
      '#suffix' => '</tbody>',
    );
    // populate tbody
    foreach($objects as $object) {
      $tbody[] = build_row($object, $mapping);
    }
    return $tbody;
  }
  
  function build_row($object, $mapping) {
    // build row
    $row = array(
      '#type' => 'markup',
      '#prefix' => '<tr>',
      '#suffix' => '</tr>',
    );
    //populate row
    foreach($mapping as $header => $prop) {
      $row[] = array(
        '#type' => 'markup',
        '#markup' => $object->$prop,
        '#prefix' => '<td>',
        '#suffix' => '</td>',
      );
    }
    return $row;
  }