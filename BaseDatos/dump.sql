--
-- PostgreSQL database dump
--

-- Dumped from database version 10.3
-- Dumped by pg_dump version 10.3

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: estadorep; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.estadorep (
    id_estadorep integer NOT NULL,
    estado_estadorep character varying(50) NOT NULL
);


ALTER TABLE public.estadorep OWNER TO usuario;

--
-- Name: id_seq; Type: SEQUENCE; Schema: public; Owner: usuario
--

CREATE SEQUENCE public.id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.id_seq OWNER TO usuario;

--
-- Name: informacion; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.informacion (
    id_informacion integer NOT NULL,
    uuid_informacion uuid NOT NULL,
    fk_id_estadorep_informacion integer,
    fk_id_tiendas_informacion integer,
    fk_id_modelo_informacion integer NOT NULL,
    reparacion character varying(50) NOT NULL
);


ALTER TABLE public.informacion OWNER TO usuario;

--
-- Name: modelos; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.modelos (
    id_modelos integer NOT NULL,
    nombre_modelos character varying(50) NOT NULL
);


ALTER TABLE public.modelos OWNER TO usuario;

--
-- Name: tecnicos; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.tecnicos (
    id_tecnicos integer NOT NULL,
    nombre_tecnicos character varying(50) NOT NULL
);


ALTER TABLE public.tecnicos OWNER TO usuario;

--
-- Name: tiendas; Type: TABLE; Schema: public; Owner: usuario
--

CREATE TABLE public.tiendas (
    id_tiendas integer NOT NULL,
    nombre_tiendas character varying(50) NOT NULL,
    localizacion_tiendas character varying(50)
);


ALTER TABLE public.tiendas OWNER TO usuario;

--
-- Data for Name: estadorep; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.estadorep (id_estadorep, estado_estadorep) FROM stdin;
1	en reparacion
2	reparado
\.


--
-- Data for Name: informacion; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.informacion (id_informacion, uuid_informacion, fk_id_estadorep_informacion, fk_id_tiendas_informacion, fk_id_modelo_informacion, reparacion) FROM stdin;
2	d7a58b0e-bc82-48e6-bd08-bc061a97e73c	1	1	1	Pantalla rota
\.


--
-- Data for Name: modelos; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.modelos (id_modelos, nombre_modelos) FROM stdin;
1	Samsung galaxy 7
2	Xiaomi mi 8 pro
\.


--
-- Data for Name: tecnicos; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.tecnicos (id_tecnicos, nombre_tecnicos) FROM stdin;
1	Pepe
2	Juan
\.


--
-- Data for Name: tiendas; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.tiendas (id_tiendas, nombre_tiendas, localizacion_tiendas) FROM stdin;
1	Mobiles Pepe	Calle de Pepe el Grande
\.


--
-- Name: id_seq; Type: SEQUENCE SET; Schema: public; Owner: usuario
--

SELECT pg_catalog.setval('public.id_seq', 1, false);


--
-- Name: estadorep estadorep_pkey; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.estadorep
    ADD CONSTRAINT estadorep_pkey PRIMARY KEY (id_estadorep);


--
-- Name: informacion informacion_pkey; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.informacion
    ADD CONSTRAINT informacion_pkey PRIMARY KEY (id_informacion);


--
-- Name: modelos modelos_pkey; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.modelos
    ADD CONSTRAINT modelos_pkey PRIMARY KEY (id_modelos);


--
-- Name: tecnicos tecnicos_pkey; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.tecnicos
    ADD CONSTRAINT tecnicos_pkey PRIMARY KEY (id_tecnicos);


--
-- Name: tiendas tiendas_pkey; Type: CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.tiendas
    ADD CONSTRAINT tiendas_pkey PRIMARY KEY (id_tiendas);


--
-- Name: informacion fk_idestadorep; Type: FK CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.informacion
    ADD CONSTRAINT fk_idestadorep FOREIGN KEY (fk_id_estadorep_informacion) REFERENCES public.estadorep(id_estadorep);


--
-- Name: informacion fk_idmodelo; Type: FK CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.informacion
    ADD CONSTRAINT fk_idmodelo FOREIGN KEY (fk_id_modelo_informacion) REFERENCES public.modelos(id_modelos);


--
-- Name: informacion fk_idtiendas; Type: FK CONSTRAINT; Schema: public; Owner: usuario
--

ALTER TABLE ONLY public.informacion
    ADD CONSTRAINT fk_idtiendas FOREIGN KEY (fk_id_tiendas_informacion) REFERENCES public.tiendas(id_tiendas);


--
-- PostgreSQL database dump complete
--

