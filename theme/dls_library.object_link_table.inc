
<?php

  module_load_include('inc', 'dls_library', 'theme/dls_library.custom_button');

  /*************************************************************
   *
   *  @param: objects = array
   *  @param: mapping = array of heading => array('display', 'baseURL', 'keepParams')
   *  @param: class = string
   *  @returns: drupal render array
   *
   *************************************************************/

  function theme_object_link_table($variables) {
  

    // Validate and set objects property
    if((gettype($variables['objects']) == 'array')) { 
      $objects = $variables['objects'];
    }
    else {
      form_set_error('', 'theme object_link_table - objects should be array. Received ' . gettype($variables['objects']) . '.');
      return;
    }
    // Validate and set mapping property
    if((gettype($variables['mapping']) == 'array')) { 
      $mapping = $variables['mapping'];
    }
    else {
      form_set_error('', 'theme object_link_table - mapping should be array. Received ' . gettype($variables['mapping']) . '.');
      return;
    }
    // Validate and set class property
    if((gettype($variables['class']) == 'string')) { 
      $class = $variables['class'];
    }
    else {
      $class = '';
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
    foreach($mapping as $header => $linkSettings) {
      // add td to row
      $row[] = build_td($object, $linkSettings);
    }
    return $row;
  }
  
  function build_td($object, $linkSettings) {
    // grab link settings
    $prop = $linkSettings['display'];
    $queryProp = isset($linkSettings['queryProp']) ? $linkSettings['queryProp'] : $prop;
    $value = $object->$queryProp;
    $display = $object->$prop;
    $url = isset($linkSettings['baseURL']) ? $linkSettings['baseURL'] : FALSE;
    // check if we need to add in a url
    if($url) {
      // check if we should preserve the current query params in the new link
      $keepParams = isset($linkSettings['keepParams']) ? $linkSettings['keepParams'] : FALSE;
      if($keepParams) {
        $params = drupal_get_query_parameters();
      }
      else {
        $params = array();
      }
      $params[$queryProp] = $value;
      $url = url($url, array('query' => $params));
      // render the td with link
      $td = array(
        '#type' => 'markup',
        'link' => theme('custom_button', array(
          'display' => $display,
          'url' => $url,
          'class' => 'table-link',
        )),
        '#prefix' => '<td>',
        '#suffix' => '</td>',
      );
    }
    else {
      // render the td without a link
      $td = array(
        '#type' => 'markup',
        '#markup' => $display,
        '#prefix' => '<td>',
        '#suffix' => '</td>',
      );
    }
    
    return $td;
  }