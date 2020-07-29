import React from 'react';

import Nav from './components/Nav.js'
import SearchPersonInterface from './components/SearchPersonInterface/SearchPersonInterface.js'
import AddPersonInterface from './components/AddPersonInterface/AddPersonInterface.js'
import DeletePersonInterface from './components/DeletePersonInterface/DeletePersonInterface.js'
import ModifyPersonInterface from './components/ModifyPersonInterface/ModifyPersonInterface.js'

class App extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      isSearchPersonInterfaceVisible: false,
      isAddPersonInterfaceVisible: false,
      isDeletePersonInterfaceVisible: false,
      isModifyPersonInterfaceVisible: false
    }
    this.updateSearchPerson = this.updateSearchPerson.bind(this)
    this.updateAddPerson = this.updateAddPerson.bind(this)
    this.updateDeletePerson = this.updateDeletePerson.bind(this)
    this.updateModifyPerson = this.updateModifyPerson.bind(this)
  }



  //makes all windows invisible
  setOrigin() {
    this.setState({
      isSearchPersonInterfaceVisible: false,
      isAddPersonInterfaceVisible: false,
      isDeletePersonInterfaceVisible: false,
      isModifyPersonInterfaceVisible: false
    })
  }
  //functions to update the state variables
  updateSearchPerson(text) {
    this.setOrigin()
    this.setState({ isSearchPersonInterfaceVisible: true })
  }
  updateAddPerson() {
    this.setOrigin()
    this.setState({ isAddPersonInterfaceVisible: true })
  }
  updateDeletePerson() {
    this.setOrigin()
    this.setState({ isDeletePersonInterfaceVisible: true })
  }
  updateModifyPerson() {
    this.setOrigin()
    this.setState({ isModifyPersonInterfaceVisible: true })
  }


  render() {
    return (
      //giving the functions to Nav component in order to execute them on button click
      //giving the state variables to the specific main components in order to make the visible or not
      <div>
        <Nav updateSearchPerson={this.updateSearchPerson} updateAddPerson={this.updateAddPerson} updateDeletePerson={this.updateDeletePerson} updateModifyPerson={this.updateModifyPerson} />
        <SearchPersonInterface isVisible={this.state.isSearchPersonInterfaceVisible} />
        <AddPersonInterface isVisible={this.state.isAddPersonInterfaceVisible} />
        <DeletePersonInterface isVisible={this.state.isDeletePersonInterfaceVisible} />
        <ModifyPersonInterface isVisible={this.state.isModifyPersonInterfaceVisible} />
      </div>
    );
  }

}

export default App;
