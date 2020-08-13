import React from 'react'

//var clientModule = require("bindings")("client.node");
//module.exports = clientModule; // Just reexport it
const clientModule = require('../../../build/Release/client.node')

class AddPersonInterface extends React.Component {
    constructor() {
        super()
        this.state = {
            firstName: "",
            lastName: "",
            birthday: "",
            phoneNumber: "",
            landlineNumber: "",
            street: "",
            city: "",
            postcode: null
        }
        this.handleChange = this.handleChange.bind(this)
        this.submitAddPerson = this.submitAddPerson.bind(this)
    }

    handleChange(event) {
        this.setState({
            [event.target.name]: event.target.value
        })
    }

    submitAddPerson() {
        clientModule.sendAddPersonServerJs(this.state.firstName, this.state.lastName, this.state.birthday, this.state.phoneNumber, this.state.landlineNumber, this.state.street, this.state.city, this.state.postcode)
        console.log("Button pressed")
    }

    render() {

        //decide if component is visible or not
        return (
            <div id="addPersonInterface" className={this.props.isVisible ? "section-visible" : "section-invisible"}>
                <div className="topbar">
                    <div className="decideField">
                        <h3>Normal</h3>
                        <h3>Map</h3>
                    </div>
                </div>
                <div className="addPerson-textfield">
                    <div className="inner-wrapper">
                        <div className="section-wrapper">
                            <h3>Person</h3>
                            <div className="person-inputFields">
                                <div className="first-lastName-input">
                                    <div className="firstName-inputField">
                                        <div className="input-heading">
                                            <p>First name</p>
                                        </div>
                                        <div className="input-field">
                                            <input name="firstName" placeholder="John" type="text" onChange={this.handleChange} />
                                        </div>
                                    </div>
                                    <div className="lastName-inputField">
                                        <div className="input-heading">
                                            <p>Last name</p>
                                        </div>
                                        <div className="input-field">
                                            <input name="lastName" placeholder="Doe" type="text" onChange={this.handleChange} />
                                        </div>
                                    </div>
                                </div>
                                <div className="birthday-input">
                                    <div className="input-heading">
                                        <p>Birthday</p>
                                    </div>
                                    <div className="input-field">
                                        <input name="birthday" placeholder="31.12.1900" type="text" onChange={this.handleChange} />
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div className="section-wrapper">
                            <h3>Contakt Information</h3>
                            <div className="contaktInformation-inputFields">
                                <div className="landlineNumber-input">
                                    <div className="input-heading">
                                        <p>Landline number</p>
                                    </div>
                                    <div className="input-field">
                                        <input name="landlineNumber" placeholder="00000/1111111" type="text" onChange={this.handleChange} />
                                    </div>
                                </div>
                                <div className="mobilePhoneNumber-input">
                                    <div className="input-heading">
                                        <p>Mobile phone number</p>
                                    </div>
                                    <div className="input-field">
                                        <input name="phoneNumber" placeholder="0152/000000000" type="text" onChange={this.handleChange} />
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div className="section-wrapper">
                            <h3>Address</h3>
                            <div className="address-inputFields">
                                <div className="street-input">
                                    <div className="input-heading">
                                        <p>Street</p>
                                    </div>
                                    <div className="input-field">
                                        <input name="street" placeholder="Examplestreet 24" type="text" onChange={this.handleChange} />
                                    </div>
                                </div>
                                <div className="postcode-city-input">
                                    <div className="postcode-inputField">
                                        <div className="input-heading">
                                            <p>Postcode</p>
                                        </div>
                                        <div className="input-field">
                                            <input name="postcode" placeholder="00000" type="text" onChange={this.handleChange} />
                                        </div>
                                    </div>
                                    <div className="city-inputField">
                                        <div className="input-heading">
                                            <p>City</p>
                                        </div>
                                        <div className="input-field">
                                            <input name="city" placeholder="Examplecity" type="text" onChange={this.handleChange} />
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <button className="addBtn" onClick={this.submitAddPerson}>SUBMIT</button>
                </div>
            </div>
        )
    }
}

export default AddPersonInterface