function createStaff(xmlDocument, id, genderInfo, jobInfo, nameInfo, mailInfo, phoneInfo, salaryInfo, currency) {
    let employee = xmlDocument.createElement("employee");
    employee.setAttribute("id", id);
    employee.setAttribute("gender", genderInfo);
    employee.setAttribute("job", jobInfo);

    let name = xmlDocument.createElement("employeeName");
    name.textContent = nameInfo;

    let mail = xmlDocument.createElement("employeeEmail");
    mail.textContent = mailInfo;

    let phone = xmlDocument.createElement("employeePhone");
    phone.textContent = phoneInfo;

    let salary = xmlDocument.createElement("salary");
    salary.textContent = salaryInfo;
    salary.setAttribute("currency", currency);

    employee.append(name, mail, phone, salary);
    return employee;
}

function createMovie(xmlDocument, genreInfo, categoryInfo, nameInfo, actorsInfo, descriptionInfo, durationInfo, projectionsInfo, hallInfo, ticketInfo, currency) {
    let movie = xmlDocument.createElement("movie");
    movie.setAttribute("genre", genreInfo);
    movie.setAttribute("category", categoryInfo);

    let name = xmlDocument.createElement("movieName");
    name.textContent = nameInfo;

    let actors = xmlDocument.createElement("actors");
    actors.textContent = actorsInfo;

    let description = xmlDocument.createElement("movieDescription");
    description.textContent = descriptionInfo;

    let duration = xmlDocument.createElement("duration");
    duration.textContent = durationInfo;

    let projections = xmlDocument.createElement("projections");
    projections.textContent = projectionsInfo;

    let hall = xmlDocument.createElement("hall");
    hall.textContent = hallInfo;

    let ticket = xmlDocument.createElement("ticket");
    ticket.textContent = ticketInfo;
    ticket.setAttribute("currency", currency);

    movie.append(name, actors, description, duration, projections, hall, ticket);
    return movie;
}

function createOffer(xmlDocument, typeInfo, nameInfo, quantityInfo, priceInfo, currency) {
    let offer = xmlDocument.createElement("offer");
    offer.setAttribute("type", typeInfo);

    let name = xmlDocument.createElement("productName");
    name.textContent = nameInfo;

    let quantity = xmlDocument.createElement("quantity");
    quantity.textContent = quantityInfo;

    let price = xmlDocument.createElement("price");
    price.textContent = priceInfo;
    price.setAttribute("currency", currency);

    offer.append(name, quantity, price);
    return offer;
}

function createXMLDocument() {
    let documentImplementation = document.implementation;
    let xmlDocument = documentImplementation.createDocument(null, null);

    let processingInstruction = document.createProcessingInstruction('xml', 'version="1.0" encoding="utf-8"');
    xmlDocument.appendChild(processingInstruction);

    let cinema = xmlDocument.createElement("cinema");

    let cinemaName = xmlDocument.createElement("cinemaName");
    cinemaName.textContent = "Кино Арена - Варна";

    let contacts = xmlDocument.createElement("contacts");
    let country = xmlDocument.createElement("country");
    let city = xmlDocument.createElement("city");
    let street = xmlDocument.createElement("street");
    let email = xmlDocument.createElement("email");
    let phone = xmlDocument.createElement("phone");
    country.textContent = "България";
    city.textContent = "Варна";
    street.textContent = "ул. Акад. Андрей Сахаров";
    email.textContent = "kino_varna@kinoarena.bg";
    phone.textContent = "02 4047 133";
    contacts.append(country, city, street, email, phone);

    let staff = xmlDocument.createElement("staff");
    let one = createStaff(xmlDocument, 1, "Мъж", "Касиер", "Христо Иванов", "VasoGechev@abv.bg", "0888 848 323", 1800, "BGN");
    let two = createStaff(xmlDocument, 2, "Жена", "Разпоредител", "Карина Цецкова", "Karina_Snejanova@gmail.bg", "0887 358 627", 1300, "BGN");
    let three = createStaff(xmlDocument, 3, "Жена", "Касиер", "Сийка Теодославова", "SijkaValentinova@yahoo.bg", "0889 096 875", 1150, "BGN");
    let four = createStaff(xmlDocument, 4, "Жена", "КафеСлужител", "Мариела Янова", "MarielaRozalinova@abv.bg", "0888 768 598", 1150, "BGN");
    staff.append(one, two, three, four);

    let movies = xmlDocument.createElement("movies");
    let movieOne = createMovie(xmlDocument, "Фантастика", "3Д", "Спайдърмен: Няма път към дома",
        "\n\t\t\t" +
        "  Зендая, Том Холанд, Бенедикт Къмбърбач, Мариса Томей, Джейми Фокс, Ангури Райс" +
        "\n\t\t\t",
        "\n\t\t\t" +
        "  Питър Паркър е свалил маската и вече не може да раздели нормалния си живот от този на супергерой.\n\t\t\t" +
        "  Когато моли за помощ Доктор Стрейндж, залогът става още по-опасен.\n\t\t\t" +
        "  Питър ще разбере какво наистина означава да си Спайдърмен." +
        "\n\t\t\t",
        "150 минути", "15:00, 16:30, 20:15", "2", 11, "BGN");

    let movieTwo = createMovie(xmlDocument, "Екшън", "2Д", "Матрицата: Възкресение",
        "\n\t\t\t" +
        "  Киану Рийвс, Приянка Чопра, Джейда Пинкет Смит, Джонатан Гроф, Джесика Хенуик, Яхия Абдул-Матийн ІІ, Кари-Ан Мос" +
        "\n\t\t\t",
        "\n\t\t\t" +
        "  Продължение на историята обединява кинематографичните икони Neo And Trinity,\n\t\t\t" +
        "  докато се впускат обратно в Матрицата и още по -дълбоко в заешката дупка.\n\t\t\t" +
        "  Съкрушително ново приключение с екшън и епичен мащаб, то е разположено в познат,\n\t\t\t" +
        "  но още по-провокативен свят, където реалността е по-субективна от всякога.\n\t\t\t" +
        "  Всичко, което е необходимо, за да се види истината, е да освободите ума си." +
        "\n\t\t\t",
        "155 минути", "13:15, 18:15, 21:15", "3", 9, "BGN");

    let movieThree = createMovie(xmlDocument, "Комедия", "2Д", "Бай Иван: Филмът",
        "\n\t\t\t" +
        "  Димитър Кирязов, Силвия Йорданова" +
        "\n\t\t\t",
        "\n\t\t\t" +
        "  Филмът е базиран на изключително популярния образ Бай Иван от Youtube канала “Светът на Ванката”." +
        "\n\t\t\t",
        "95 минути", "14:15, 19:00", "1", 9, "BGN");

    let movieFour = createMovie(xmlDocument, "Мистерии", "2Д", "Улицата на кошмарите",
        "\n\t\t\t" +
        "  Брадли Купър, Кейт Бланшет, Руни Мара и Тони Колет" +
        "\n\t\t\t",
        "\n\t\t\t" +
        "  Улицата на кошмарите е адаптация на едноименния роман на Уилям Линдзи Грешам от 1946 година\n\t\t\t" +
        "  и разказва за Стантън Карлайл (Брадли Купър) – бивш карнавален работник,\n\t\t\t" +
        "  който се превръща в една от топ атракциите в нощните клубове на големия град.\n\t\t\t" +
        "  Чрез различни трикове, които заимства от своята колежка Моли (Тони Колет),\n\t\t\t" +
        "  както и с помощта на приятелката си Зийна (Руни Мара), Стантън създава впечатлението,\n\t\t\t" +
        "  че е могъщ медиум, способен да чете умовете на хората. Първоначално идеята е просто да\n\t\t\t" +
        "  впечатлява и забавлява тълпата на карнавала, но стремежът към слава и богатство става\n\t\t\t" +
        "  причина представлението да  се превърне в средство за финансови измами,\n\t\t\t" +
        "  чиято цел са по-заможните жители на града. Така Стантън попада в полезрението на\n\t\t\t" +
        "  психиатъра д-р Лилит Ритър (Кейт Бланшет), която се опитва да\n\t\t\t" +
        "  го изобличи като шарлатанин, но впоследствие става част от схемите му." +
        "\n\t\t\t",
        "150 минути", "14:30, 17:45, 20:45", "4", 9, "BGN");

    movies.append(movieOne, movieTwo, movieThree, movieFour);

    let food = xmlDocument.createElement("food");
    let offerOne = createOffer(xmlDocument, "Храна", "Пуканки", "Средни", 5.99, "BGN");
    let offerTwo = createOffer(xmlDocument, "Храна", "Пуканки", "Големи", 7.99, "BGN");
    let offerThree = createOffer(xmlDocument, "Храна", "Начос", "500гр", 7.99, "BGN");
    let offerFour = createOffer(xmlDocument, "Напитка", "Кола", "500мл.", 6.99, "BGN");
    let offerFive = createOffer(xmlDocument, "Напитка", "Кола", "750мл.", 8.99, "BGN");
    food.append(offerOne, offerTwo, offerThree, offerFour, offerFive);

    cinema.append(cinemaName, contacts, staff, movies, food);
    xmlDocument.appendChild(cinema);

    return xmlDocument;
}

function serializeDocument(doc) {
    let serializer = new XMLSerializer();
    let serializedDocument = serializer.serializeToString(doc);

    return vkbeautify.xml(serializedDocument);
}

function showGeneratedXML(content) {
    let generatedXmlHtmlElement = document.getElementById('generatedXML');
    generatedXmlHtmlElement.innerText = content;
}

function generateXML(){
    let doc = createXMLDocument();

    showGeneratedXML(serializeDocument(doc));
}

/*function createEmployee(xmlDocument, id, employeeNameContent, genderContent, addressContent, positionContent, salaryContent, currency) {
    let employee = xmlDocument.createElement("employee");
    employee.setAttribute("id", id);

    let employeeName = xmlDocument.createElement("employee_name");
    employeeName.textContent = employeeNameContent;

    let gender = xmlDocument.createElement("gender");
    gender.textContent = genderContent;

    let address = xmlDocument.createElement("address");
    address.textContent = addressContent;

    let position = xmlDocument.createElement("position");
    position.textContent = positionContent;

    let salary = xmlDocument.createElement("salary");
    salary.textContent = salaryContent;
    salary.setAttribute("currency", currency);

    employee.append(employeeName, gender, address, position, salary);
    return employee;
}

function createProduct(xmlDocument, type, brandContent, modelContent, descriptionContent, quantityContent, priceContent, currency) {
    let product = xmlDocument.createElement("product");
    product.setAttribute("type", type);

    let brand = xmlDocument.createElement("brand");
    brand.textContent = brandContent;

    let model = xmlDocument.createElement("model");
    model.textContent = modelContent;

    let description = xmlDocument.createElement("product_description");
    description.textContent = descriptionContent;

    let quantity = xmlDocument.createElement("quantity");
    quantity.textContent = quantityContent;

    let price = xmlDocument.createElement("price");
    price.textContent = priceContent;
    price.setAttribute("currency", currency);

    product.append(brand, model, description, quantity, price);
    return product;
}

function createService(xmlDocument, type, nameContent, descriptionContent, costContent, currency) {
    let service = xmlDocument.createElement("service");
    service.setAttribute("type", type);

    let name = xmlDocument.createElement("service_name");
    name.textContent = nameContent;

    let description = xmlDocument.createElement("service_description");
    description.textContent = descriptionContent;

    service.append(name, description);

    if (Boolean(costContent) === true) {
        let cost = xmlDocument.createElement("cost");
        cost.textContent = costContent;
        cost.setAttribute("currency", currency);
        service.appendChild(cost);
    }

    return service;
}

function createXMLDocument() {
    let documentImplementation = document.implementation;
    let xmlDocument = documentImplementation.createDocument(null, null);

    let processingInstruction = document.createProcessingInstruction('xml', 'version="1.0" encoding="utf-8"');
    xmlDocument.appendChild(processingInstruction);

    let techShop = xmlDocument.createElement("tech_shop");

    let shopName = xmlDocument.createElement("shop_name");
    shopName.textContent = "Технополис";

    let contacts = xmlDocument.createElement("contacts");
    let country = xmlDocument.createElement("country");
    let city = xmlDocument.createElement("city");
    let street = xmlDocument.createElement("street");
    let email = xmlDocument.createElement("email");
    let phone = xmlDocument.createElement("phone");
    country.textContent = "България";
    city.textContent = "Варна";
    street.textContent = "бул. \"Владислав Варненчик\" 277";
    email.textContent = "eshop@technopolis.bg";
    phone.textContent = "052 / 509 060";
    contacts.append(country, city, street, email, phone);

    let employees = xmlDocument.createElement("employees");
    employees.setAttribute("count", "4");
    let employeeOne = createEmployee(xmlDocument, 1, "Георги Станчев", "Мъж", "ул. \"Паско Пенев Желев\" 11", "Мениджър", 1800, "BGN");
    let employeeTwo = createEmployee(xmlDocument, 2, "Кристина Тодорова", "Жена", "Варна сити парк ЮГ", "Касиер", 1600, "BGN");
    let employeeThree = createEmployee(xmlDocument, 3, "Васил Любомиров", "Мъж", "ул. \"Генерал Гурко\" 15А", "Работник в склад", 1400, "BGN");
    let employeeFour = createEmployee(xmlDocument, 4, "Светослав Георгиев", "Мъж", "кв. \"Възраждане\" III 68", "Продавач-консултант", 1000, "BGN");
    employees.append(employeeOne, employeeTwo, employeeThree, employeeFour);

    let products = xmlDocument.createElement("products");
    products.setAttribute("count", "6");
    let productOne = createProduct(xmlDocument, "Телевизор", "SONY", "XR-77A83J", "4K Ultra HD OLED SMART TV, ANDROID TV, 77 inch, 195.0 см", 32, "5 999.00");
    let productTwo = createProduct(xmlDocument, "Лаптоп", "APPLE", "MacBook AIR 13", "13.3 inch, APPLE M1 CHIP, RAM 8 GB, SSD 512 GB, APPLE 8 CORE GPU, MAC OS, SILVER", 27, "2 600.00");
    let productThree = createProduct(xmlDocument, "Смартфон", "XIAOMI", "REDMI NOTE 9 PRO", "GRAY 6.67 inch, 128 GB, RAM 6 GB, 64+8+5+2 MP", 58, "429.99");
    let productFour = createProduct(xmlDocument, "Съдомиялнa", "BOSCH", "SMS4HVW33E",
        "\n\t\t\t\t" +
        "Гъвкаво зареждане и интелигентно дистанционно управление на вашата съдомиялна машина чрез приложението Home Connect.\n\t\t\t\t" +
        "ExtraDry: допълнителна опция за оптимално изсушаване на съдовете\n\t\t\t\t" +
        "Silence on demand: с до 30 мин се намалява шума на минимум по-всяко време чрез приложението Home Connect  App.\n\t\t\t\t" +
        "Home Connect: домакински уред със Smart свързаност за улеснение на Вашето ежедневие\n\t\t\t\t" +
        "Любима функция: персонализирана функция само с едно докосване.\n\t\t\t",
        15, "849.99");
    let productFive = createProduct(xmlDocument, "Прахосмукачка", "ROWENTA", "RR7375WH",
        "\n\t\t\t\t" +
        "Прахосмукачката-робот Rowenta X-PLORER Serie 50 е удобно решение за автоматично почистване на дома,\n\t\t\t\t" +
        "което предлага безпроблемно почистване без вашата намеса. Със специални функции за грижа за животните,\n\t\t\t\t" +
        "създадени за нуждите на собствениците на домашни любимци. Открийте високотехнологична автоматична прахосмукачка,\n\t\t\t\t" +
        "която достига навсякъде, където имате нужда от нея: интелигентна навигация, усъвършенствана инфрачервена технология и\n\t\t\t\t" +
        "изключително интуитивен удобен за потребителя интерфейс, включително съвместимост с мобилно приложение и гласов асистент.\n\t\t\t",
        41, "389.00");
    let productSix = createProduct(xmlDocument, "Електрическа тротинетка", "SEGWAY", "KICKSCOOTER E25E",
        "\n\t\t\t\t" +
        "С Ninebot KickScooter E25E не е нужно да избирате между удобство, стил и комфорт.\n\t\t\t\t" +
        "Той комбинира и трите. Освен, че предлага по-висока скорост на придвижване и по-голям пробег,\n\t\t\t\t" +
        "E25E е снабден и с допълнителни LED светлини, разположени под мястото за крака,\n\t\t\t\t" +
        "които можете да настроите спрямо Вашето настроение и стил.\n\t\t\t\t" +
        "Задвижваният от предното колело KickScooter E25E е снабден с 215Wh (5960 mAh) литиево-йонна батерия,\n\t\t\t\t" +
        "която позволява да ускорите до максимум 25 км/ч и да изминете до 25 км.\n\t\t\t",
        50, "799.99");
    products.append(productOne, productTwo, productThree, productFour, productFive, productSix);

    let services = xmlDocument.createElement("services");
    services.setAttribute("count", "3");
    let serviceOne = createService(xmlDocument, "Основна", "Smart Care - случайно счупване, намокряне и кражба чрез взлом",
        "\n\t\t\t\t" +
        "Специализирана услуга за мобилни телефони, лаптопи, монитори, настолни компютри.\n\t\t\t\t" +
        "Покрива повреди, които не са включени в търговската гаранция, като случайно счупване, намокряне и кражба чрез взлом.\n\t\t\t\t" +
        "Може да се възползвате от услугата само в деня на закупуване на устройството.\n\t\t\t\t" +
        "Цената се определя в зависимост от стойността на устройството.\n\t\t\t",
        null, "");
    let serviceTwo = createService(xmlDocument, "Основна", "Рециклиране",
        "\n\t\t\t\t" +
        "Всички можем много лесно да участваме активно в подпомагане на усилията за опазване на околната среда\n\t\t\t\t" +
        "като доброволно и безвъзмездно предадем на организация по оползотворяване на отпадъците\n\t\t\t\t" +
        "излязло от употреба електрическо и електронно оборудване.\n\t\t\t",
        "", "");
    let serviceThree = createService(xmlDocument, "Допълнителна", "Доставка до врата",
        "\n\t\t\t\t" +
        "Уважаеми Клиенти, ТЕХНОПОЛИС Ви предоставя възможността да се възползвате от услугата \"Доставка до врата\",\n\t\t\t\t" +
        "чрез която закупени от хипермаркети ТЕХНОПОЛИС стоки ще бъдат доставени непосредствено до входната врата на Вашия дом.\n\t\t\t",
        "10.00", "BGN");
    services.append(serviceOne, serviceTwo, serviceThree);

    techShop.append(shopName, contacts, employees, products, services);
    xmlDocument.appendChild(techShop);

    return xmlDocument;
}

function serializeDocument(doc) {
    let serializer = new XMLSerializer();
    let serializedDocument = serializer.serializeToString(doc);

    return vkbeautify.xml(serializedDocument);
}

function showGeneratedXML(content) {
    let generatedXmlHtmlElement = document.getElementById('generatedXML');
    generatedXmlHtmlElement.innerText = content;
}

function generateXML(){
    let doc = createXMLDocument();

    showGeneratedXML(serializeDocument(doc));
}*/