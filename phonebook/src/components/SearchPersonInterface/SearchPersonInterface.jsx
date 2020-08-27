import React from 'react'
import OutputBox from './OutputBox.jsx'
import PersonNotFound from './PersonNotFound.jsx'
import axios from 'axios';
const Querystring = require('querystring');





class SearchPersonInterface extends React.Component {

    constructor() {
        super()
        this.state = {
            firstName: "",
            lastName: "",
            fullName: "",
            persons: [],
            personFound: false,
            personNotFound: false

        }
        this.handleClick = this.handleClick.bind(this)
        this.handleChange = this.handleChange.bind(this)
        this.splitString = this.splitString.bind(this)
    }


    //Changes fullName, when inputField is changed
    handleChange(event) {
        this.setState({
            fullName: event.target.value
        }, this.splitString);
    }

    //execute the function
    handleClick() {
        let body = Querystring['stringify']({
            firstName: this.state.firstName,
            lastName: this.state.lastName
        })
        //create the config header file for request
        const config = {
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            }
        }

        axios.post('http://127.0.0.1:1234/searchPerson', body, config)
            .then(response => {
                //open PersonNotFound component
                if (response.data.firstName === "Not found") {
                    this.setState({
                        personNotFound: true,
                        personFound: false
                    })
                }
                //open Outputbox components
                else {
                    this.setState({
                        persons: response.data,
                        personNotFound: false,
                        personFound: true
                    });
                }
            })
            .catch(function (error) {
                alert("Error connecting to the server. Maybe it´s offline")
            })
    };

    //splits the full input into two variables in order to put it in the function
    splitString() {
        var name = this.state.fullName.split(' ')
        this.setState({
            firstName: name[0],
            lastName: name[1]
        })
    }


    render() {

        const personComponents = this.state.persons.map(person => <OutputBox persons={person} />)
        //decide if component is visible or not
        return (
            <div id="searchPersonInterface" className="routed_section">

                <div className="topbar">

                </div>
                <div className="input-textfield">
                    <div className="con-input">
                        <input placeholder="Person" type="text" onChange={this.handleChange} ></input>
                    </div>
                    <button className="submitBtn" onClick={this.handleClick}>Search</button>
                </div>

                <div className={this.state.personFound ? "visible" : "invisible"}>
                    {personComponents}
                </div>
                <div className={this.state.personNotFound ? "visible" : "invisible"}>
                    <PersonNotFound />
                </div>

            </div >

        )
    }
}

export default SearchPersonInterface