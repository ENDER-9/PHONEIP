import React from 'react';
import axios from 'axios';
const Querystring = require('querystring');


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
            postcode: null,
        }
        this.handleChange = this.handleChange.bind(this)
        this.submitAddPerson = this.submitAddPerson.bind(this)
    }

    handleChange(event) {
        this.setState({
            [event.target.name]: event.target.value
        })
    }

    async submitAddPerson() {
        //create the post request Querystring
        let body = Querystring['stringify']({
            firstName: this.state.firstName,
            lastName: this.state.lastName,
            birthday: this.state.birthday,
            phoneNumber: this.state.phoneNumber,
            landlineNumber: this.state.landlineNumber,
            street: this.state.street,
            city: this.state.city,
            postcode: this.state.postcode
        })
        //create the config header file for request
        const config = {
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            }
        }
        axios.post('http://127.0.0.1:1234/addPerson', body, config)
            .then(response => console.log(response.data));
    }

    render() {

        //decide if component is visible or not
        return (
            <div id="addPersonInterface" className="routed_section">
                <div className="topbar">
                    <div className="decideField">

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