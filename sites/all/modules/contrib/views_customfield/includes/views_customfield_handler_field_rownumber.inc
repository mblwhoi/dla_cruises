<?php

/**
 * @file
 * Contains the 'customfield' rownumber field handler.
 */

/**
 * Field handler to provide a rownumber.
 */
class views_customfield_handler_field_rownumber extends views_handler_field {
  var $rownumber;
  
  function init(&$view, $options) {
    parent::init($view, $options);
    
    $this->rownumbers = 0;
  }
  
  function query() {
    // Override parent::query() and don't alter query.
    $this->field_alias = 'customfield_rownumber_'. $this->position;
  }

  function render($values) {
    if ($this->view->pager['use_pager']) {
      return ++$this->rownumbers + ($this->view->pager['current_page'] * $this->view->pager['items_per_page']) + $this->view->pager['offset'];
    }else {
      return ++$this->rownumbers;
    }
  }
}
